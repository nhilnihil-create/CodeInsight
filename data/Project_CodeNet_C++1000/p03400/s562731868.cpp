#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll N, D, X, ans = 0;
    cin >> N >> D >> X;
    ll A[N];
    for(int i = 0; i < N; i++) cin >> A[i];

    ans += X;
    for(int i = 0; i < N; i++) ans += 1 + (D - 1)  / A[i];

    cout << ans << endl;

}