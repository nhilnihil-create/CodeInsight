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

    ll H, W, N, sr, sc; string S, T;
    cin >> H >> W >> N >> sr >> sc >> S >> T;
    sr--; sc--;

    reverse(S.begin(), S.end());
    reverse(T.begin(), T.end());

    ll left = 0, right = W-1, up = 0, down = H-1;
    Rep (i, N) {
        if (T[i] == 'L') right = min(right+1, W-1);
        if (T[i] == 'R') left = max(left-1, (ll)0);
        if (T[i] == 'U') down = min(down+1, H-1);
        if (T[i] == 'D') up = max(up-1, (ll)0);
        if (S[i] == 'L') left++;
        if (S[i] == 'R') right--;
        if (S[i] == 'U') up++;
        if (S[i] == 'D') down--;
        if (left > right || up > down) {
            cout << "NO\n";
            return 0;
        }
    }

    // cout << left << " " << right << " " << up << " " << down << endl;
    if (left <= sc && sc <= right && up <= sr && sr <= down) cout << "YES\n";
    else cout << "NO\n";
}