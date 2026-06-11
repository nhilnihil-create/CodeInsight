#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const int MOD = 1000000007;
using ping = pair<ll, ll>;

int main(){
    ll N;
    cin >> N;
    vector<ll> X(N);
    vector<ll> orderd(N);
    for (int i = 0; i < N; i++) {
      ll a;
      cin >> a;
      X[i] = a, orderd[i] = a;
    }

    sort(orderd.begin(), orderd.end());

    for (int i = 0; i<N; i++){
      if(X[i]<=orderd[N/2-1]){
        cout << orderd[N / 2] << endl;
      }
      else{
        cout << orderd[N/2-1] << endl;
      }
    }
    return 0;
}