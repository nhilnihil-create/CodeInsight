#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define FASTIO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define endl '\n'
#define pb push_back
#define pf push_front
#define mp make_pair
#define fi first
#define se second

using ll = long long;
using P = pair<ll, ll>;

/*追加部分*/



/*main関数*/

int main() {
FASTIO;
    string s; cin >> s;
    int ar[10];
    for(int i = 0; i < 3; i++){
        ar[i] = s[i] - '0';
    }

    int ans = 0;
    for(int i = 0; i < 3; i++){
        if(ar[i] == 1) ans++;
    }

    cout << ans << endl;
return 0;
}