//#pragma GCC optimization ("O3")
//#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize ("Ofast")
#pragma GCC target ("avx,avx2,fma")

#include <bits/stdc++.h>
using namespace std;

#define all(s) s.begin(), s.end()
#define ok puts("ok")
#define ll long long
#define pb push_back
#define mk make_pair
#define fr first
#define sc second
#define vi vector < int >
#define pl pair < ll, ll >
#define pi pair < int, int >
#define pii pair < ll, pi >
#define next next123
#define left left123

const int N = 1e5 + 7;
const ll INF = 1e15 + 7;

string s;

vector < pi > g;

main(){
    cin >> s;
    int n = s.length();
    s = ' ' + s;
    if (s[1] != '1' || s[n] == '1'){
        puts("-1");
        return 0;
    }
    int last = 1;
    for (int i = 1; i <= n / 2; i++){
        if (s[i] != s[n - i]){
            puts("-1");
            return 0;
        }
        g.pb(mk(last, i + 1));
        if (s[i] == '1')
            last = i + 1;
    }
    for (int i = n / 2 + 2; i <= n; i++)
        g.pb(mk(last, i));
    for (pi it : g)
        printf("%d %d\n", it.fr, it.sc);
}
