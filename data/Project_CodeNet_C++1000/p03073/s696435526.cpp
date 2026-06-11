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
int32_t main(){
    SPEED;
    string s;
    cin >> s;
    string s1 = "", s2 = "";
    int n = len(s);
    for(int i = 0; i < n; ++i){
        if(i & 1){
            s1 += '0';
            s2 += '1';
        }
        else{
            s1 += '1';
            s2 += '0';
        }
    }
    int cnt = 0, cnt1 = 0;
    for(int i = 0; i < n; ++i){
        if(s[i] != s1[i]) cnt++;
        if(s[i] != s2[i]) cnt1++;
    }
    cout << min(cnt, cnt1) ;
}