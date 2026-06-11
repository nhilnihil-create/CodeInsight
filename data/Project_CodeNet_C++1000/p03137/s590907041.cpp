#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> X(M);
    for (int i = 0; i < M; i++) cin >> X[i];
    if(N>=M){
        cout <<0 << endl;
        return 0;
    }
    sort(X.begin(), X.end());
    vector<ll> dif(M - 1);
    for (int i = 0; i < M - 1; i++){
      dif.push_back(X[i + 1] - X[i]);
    }
    sort(dif.begin(), dif.end(), greater<ll>());
    ll out = 0;
    for (int i = 0; i < N - 1; i++) out += dif[i];
    cout << X[M-1]-X[0]-out << endl;
    return 0;
}