#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  int X,Y,Z,K;
  cin >> X >> Y >> Z >> K;
  vector<ll> A(X);
  vector<ll> B(Y);
  vector<ll> C(Z);
  // A[0]=100'000'000'000;
  // B[0]=100'000'000'000;
  // C[0]=100'000'000'000;

  for (int i=1; i<=X; i++) cin >> A[i-1];
  for (int i=1; i<=Y; i++) cin >> B[i-1];
  for (int i=1; i<=Z; i++) cin >> C[i-1];
  sort(A.begin(),A.end(),greater<ll>());
  sort(B.begin(),B.end(),greater<ll>());
  sort(C.begin(),C.end(),greater<ll>());
  // for (ll i: A) cout<<i<<" ";
  // cout<<endl;
  // for (ll i: B) cout<<i<<" ";
  // cout<<endl;
  // for (ll i: C) cout<<i<<" ";
  // cout<<endl;

  vector<ll> firsty(K*K+10,0);

  for (int i=0; i<min(X,K); i++){
    for (int j=0; j<min(Y,K); j++){
      firsty[i+K*j]=A[i]+B[j];
    }
  }

  sort(firsty.begin(),firsty.end(),greater<ll>());

  vector<ll> secondy(K*K+10,0);

  for (int i=0; i<min(Z,K); i++){
    for (int j=0; j<min(K,X*Y); j++){
      secondy[i+K*j]=C[i]+firsty[j];
    }
  }

  sort(secondy.begin(),secondy.end(),greater<ll>());

  for (int i=0; i<K; i++) cout<<secondy[i]<<endl;

  

} 