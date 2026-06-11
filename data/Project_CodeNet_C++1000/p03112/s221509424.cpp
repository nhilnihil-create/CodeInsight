#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

long long MOD = 1000000000 + 7;
long long MAX = 1000000000000000000;

int main(){
  cout << setprecision(10);
  int A,B,Q;
  cin >> A >> B >> Q;

  vector<ll> S(A);
  vector<ll> T(B);
  for(int i = 0; i < A; i++){
    cin >> S[i];
  }
  for(int i = 0; i < B; i++){
    cin >> T[i];
  }

  // (S,T)から一番近い(T,S)までの距離
  vector<ll> StoT(A,MAX);
  vector<ll> TtoS(B,MAX);

  for(int i = 0; i < A; i++){
    int index = lower_bound(T.begin(), T.end(), S[i]) - T.begin();

    if(index < B)   StoT[i] = min(StoT[i], abs(S[i] - T[index]));
    if(index+1 < B) StoT[i] = min(StoT[i], abs(S[i] - T[index+1]));
    if(index-1>= 0) StoT[i] = min(StoT[i], abs(S[i] - T[index-1]));

  }
  for(int i = 0; i < B; i++){
    int index = lower_bound(S.begin(), S.end(), T[i]) - S.begin();

    if(index < A)   TtoS[i] = min(TtoS[i], abs(T[i] - S[index]));
    if(index+1 < A) TtoS[i] = min(TtoS[i], abs(T[i] - S[index+1]));
    if(index-1>= 0) TtoS[i] = min(TtoS[i], abs(T[i] - S[index-1]));

  }


  while(Q--){
    ll x;
    cin >> x;

    ll ans = MAX;
    // Sから

    // Tから
    int index;
    index = lower_bound(T.begin(), T.end(), x) - T.begin();

    if(index < B)      ans = min(ans, abs(x - T[index]) + TtoS[index]);
    if(index + 1 < B)  ans = min(ans, abs(x - T[index+1]) + TtoS[index+1]);
    if(index - 1 >= 0) ans = min(ans, abs(x - T[index-1]) + TtoS[index-1]);

    index = lower_bound(S.begin(), S.end(), x) - S.begin();
    if(index < A)      ans = min(ans, abs(x - S[index]) + StoT[index]);
    if(index+1 < A)    ans = min(ans, abs(x - S[index+1]) + StoT[index+1]);
    if(index-1 >= 0)   ans = min(ans, abs(x - S[index-1]) + StoT[index-1]);


    cout << ans << endl;

  }


}
