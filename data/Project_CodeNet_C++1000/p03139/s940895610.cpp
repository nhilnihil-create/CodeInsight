#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
using namespace std;
#define ll int64_t
#define REP(i, n) for (ll i=0; i<n; i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, A, B;
    cin >> N >> A >> B;

    ll ans1, ans2;
    ans1 = min(A, B);
    ans2 = max(0, (A + B - N));
    
    cout << ans1 << " " << ans2 << "\n";
}