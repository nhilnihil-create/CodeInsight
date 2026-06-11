#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e9;
const static ll MAXN = 301;



int main(){
    ll N; cin >> N; vector<ll> A(N), B(N), V(N);
    ll X = 0;
    for(int i = 0; i < N; i++) {cin >> A[i] >> B[i]; V[i] = A[i] + B[i]; X -= B[i];}
    sort(V.rbegin(), V.rend());
    for(int i = 0; i < N; i+=2){
        X += V[i];
    }
    cout << X << endl;
}