#include <bits/stdc++.h>
using namespace std;

int solve(vector<int> &inters){
  const size_t N= inters.size();
  if(N==1){ return 0; }
  else{
    int ret= 0;
    for(size_t i=0; i< N-1-i; i++){
      ret+= abs(inters.at(i)- inters.at(N-1-i));
    }

    return ret;
  }
}

int main(){
  string S;
  cin >> S;

  string T;
  vector<int> inters;
  int cnt= 0;
  for(auto c:S){
    if(c=='x'){
      cnt++;
    }
    else{
      T+= c;
      inters.emplace_back(cnt);
      cnt= 0;
    }
  }
  inters.emplace_back(cnt);

  string Trev;
  reverse_copy(T.begin(), T.end(), back_inserter(Trev));

  int ans= (T==Trev) ? solve(inters)
                     : -1;
  cout << ans << endl;
}