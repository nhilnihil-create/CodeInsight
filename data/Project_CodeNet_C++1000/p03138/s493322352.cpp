#include <bits/stdc++.h>
using namespace std;
const int logD= 40;

int64_t dp(int64_t Xmax, int digit, int64_t N, const vector<int64_t>& data){
  if(digit==logD){
    return 0LL;
  }
  else{
    int64_t offset1= (1LL << digit)* (N- data.at(digit));
    int64_t offset0= (1LL << digit)* data.at(digit);

    if(Xmax & 1) return dp(Xmax>>1, digit+1, N, data)+ max(offset1, offset0);
    else if (Xmax > 0) return max(dp((Xmax>>1)-1, digit+1, N, data)+ offset1, dp(Xmax>>1, digit+1, N, data)+ offset0);
    else               return dp(0LL, digit+1, N, data)+ offset0;
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

  cout << dp(Xmax, 0, N, data) << endl;
}