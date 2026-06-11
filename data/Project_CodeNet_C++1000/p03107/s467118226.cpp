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
    string s;
    cin >> s;
    int one = 0, zero = 0, ans = 0;
    for(char c: s){
        if(c == '1'){
            one++;
            if(zero > 0){
                ans += 2;
                one--;
                zero--;
            }
        }
        else{
            zero++;
            if(one > 0){
                ans += 2;
                one--;
                zero--;
            }
        }
    }
    cout << ans ;
}