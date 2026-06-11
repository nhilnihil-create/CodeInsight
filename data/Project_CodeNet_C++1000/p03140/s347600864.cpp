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

    ll N;
    string A, B, C;
    cin >> N >> A >> B >> C;

    ll ans = 0;
    Rep (i, N) {
        set<char> letter;
        letter.insert(A[i]);
        letter.insert(B[i]);
        letter.insert(C[i]);

        ans += letter.size() - 1;
    }

    cout << ans << endl;
}