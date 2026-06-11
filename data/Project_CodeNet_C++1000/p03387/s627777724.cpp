#include <bits/stdc++.h>
using namespace std;
#define SPEED ios::sync_with_stdio(false); cin.tie(0); cout.tie(0)
#define int long long
#define ld long double
#define fi first
#define se second
#define all(uiet) uiet.begin(),uiet.end()
#define read(UIET) for(int i = 0; i < n; ++i) cin >> UIET[i]
#define out(UIET) for(int i = 0; i < n; ++i) cout << UIET[i]
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define vpp vector<pair< int, int > >
#define pll pair<int , int >
#define ppll pair < pll , pll >
#define debug(n1) cout << n1 << endl
#define len(a) ((int) (a).size())
#define endl "\n"
#define mod 1000000007
const int INF=(1LL<<60)-1;
const int MAXN = 1000001;
string extractStringAtKey(string str, int key){
    char *s = strtok((char *)str.c_str(), " ");
    while(key > 1){
        s = strtok(NULL, " ");
        key--;
    }
    return (string)s;
}
int32_t main(){
    SPEED;
    int a[3];
    cin >> a[0] >> a[1] >> a[2];
    int odd = 0, even = 0;
    for(int i = 0; i < 3; ++i){
        if(a[i] & 1) odd++;
        else even++;
    }
    if(odd == 3 || even == 3){
        sort(a, a + 3);
        if(a[0] == a[1] && a[1] == a[2]){
            cout << 0;
            return 0;
        }
        if(odd == 3){
            cout << (a[2] - a[0])/2 + (a[2] - a[1])/2;
        }
        else cout << (a[2] - a[0])/2 + (a[2] - a[1])/2;
    }
    else{
        if(odd > even){
            int ans = 1;
            for(int i = 0; i < 3; ++i){
                if(a[i] & 1) a[i]++;
            }
            if(a[0] == a[1] && a[1] == a[2]){
                cout << 1;
                return 0;
            }
            sort(a, a + 3);
            cout << ans + (a[2] - a[0])/2 + (a[2] - a[1])/2;
        }
        else{
            int ans = 1;
            for(int i = 0; i < 3; ++i){
                if(a[i] % 2 == 0) a[i]++;
            }
            sort(a, a + 3);
            if(a[0] == a[1] && a[1] == a[2]){
                cout << 1;
                return 0;
            }
            cout << ans + (a[2] - a[0])/2 + (a[2] - a[1])/2;
        }
    }
}