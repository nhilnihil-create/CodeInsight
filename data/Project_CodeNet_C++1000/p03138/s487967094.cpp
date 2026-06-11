#include <bits/stdc++.h>
using namespace std;
using state= pair<int64_t, int>;
const int logD= 40;

int64_t dp(state stat, int64_t N, const vector<int64_t>& data, map<state, int64_t>& memo){
  if(memo.count(stat)){ return memo.at(stat); }
  else{
    int64_t Xmax; int digit;
    tie(Xmax, digit)= stat;

    if(digit==logD){
      return memo[stat]= 0LL;
    }
    else{
      int64_t offset1= (1LL << digit)* (N- data.at(digit));
      int64_t offset0= (1LL << digit)* data.at(digit);
      state next  = make_pair( Xmax>>1   , digit+1);
      state next_d= make_pair((Xmax>>1)-1, digit+1);

      if(Xmax & 1) return memo[stat]= dp(next, N, data, memo)+ max(offset1, offset0);
      else if (Xmax > 0) return memo[stat]= max(dp(next_d, N, data, memo)+ offset1, dp(next, N, data, memo)+ offset0);
      else               return memo[stat]= dp(next, N, data, memo)+ offset0;
    }
  }
}

int main(){
  int64_t N,Xmax,buf;
  cin >> N >> Xmax;

  vector<int64_t> data(logD);
  for(int64_t i=0; i<N; i++){
    cin >> buf;
    int cnt= 0;
    while(buf > 0){
      if(buf & 1){ data.at(cnt)++; }

      cnt++;
      buf>>= 1;
    }
  }

  map<state, int64_t> memo;
  cout << dp(make_pair(Xmax, 0), N, data, memo) << endl;
}