#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<utility>
#include<algorithm>
#include<cstdio>
#include<iomanip>
#include<queue>
#include<stack>

#define ll int64_t
#define Rep(i, n) for (ll i = 0; i < n; i++)

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;
    ll ans = S.size();
    Rep (i, S.size()-1) {
        if (S[i] != S[i+1]) {
            ans = min(ans, max(i+1, (ll)S.size()-i-1));
        }
    }

    cout << ans << endl;
}