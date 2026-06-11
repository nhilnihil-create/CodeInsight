#include <bits/stdc++.h>
#define ll long long int
#define ld long double
const ll MOD = 998244353;
const ll INF = 1e18;
using namespace std;


main(){    
    #ifdef XOX
        freopen("D:\\V S Code\\cpp\\competitiveProgramming\\Input.txt", "r", stdin);
        freopen("D:\\V S Code\\cpp\\competitiveProgramming\\OPT.txt", "w", stdout);
    #endif

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s;
    cin >> s;
    int cnt = 0;
    for(auto ch : s){
        cnt += (ch == 'o');
    }

    int n = 15 - s.length();

    if((cnt + n) >= 8)  cout << "YES\n";
    else    cout << "NO\n";
}