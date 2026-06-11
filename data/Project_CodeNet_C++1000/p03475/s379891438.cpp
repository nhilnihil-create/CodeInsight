#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> C(504),S(504),F(504);

ll G(int i,ll t){
  if(t>=S[i]){
    if(t%F[i]==0){
      return C[i];
    }
    else{
      return C[i]+F[i]-t%F[i];
    }
  }
  else{
    return S[i]-t+C[i];
  }
}

int main(){
  int N;
  cin >> N;
  for(int i=0;i<N-1;i++){
    cin >> C[i] >> S[i] >> F[i];
  }
  for(int i=0;i<N;i++){
    if(i==N-1){
      cout << 0 << endl;
      return 0;
    }
    ll ans=0; 
    for(int j=i;j<N-1;j++){
      ans+=G(j,ans);
    }
    cout << ans << endl;
  }
}