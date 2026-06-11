#include <bits/stdc++.h>

using ll = long long;
using namespace std;
const int INFint = 2e9+1;
const ll INFll = 2e18+1;
ll MOD=1e9+7;


int main(){
  int N,A,B;
  cin>>N>>A>>B;
  vector<int> P(N);
  for(int i(0);i<N;i++){
    cin>>P[i];
  }
  int cnt1(0),cnt2(0),cnt3(0);
  for(int i(0);i<N;i++){
    if(P[i]<=A){
      cnt1++;
    }else if(P[i]>B){
      cnt3++;
    }else{
      cnt2++;
    }
  }
  cout << min({cnt1,cnt2,cnt3}) << endl;
  return 0;
}

