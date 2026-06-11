#include <bits/stdc++.h>
#define ss second
#define ff first
#define all(x) x.begin(), x.end()

// #define DEBUG 100

using namespace std;
using ll = long long;
using pii = pair<int, int>;

const int oo = 1e9 + 7;
const ll mod = 1e9 + 7,maxn = 100010;
const double PI = acos(-1);



int main (){
    ios_base::sync_with_stdio(false);
    cin.tie(0); 
    
    int n, k;
    string s;
    cin >> n >> k;
    cin >> s;

    for (int i=1; i<=n; i++){
        if (i==k) cout << char(s[i-1] + 32);
        else cout << s[i-1];
    }

    cout << endl;
    return 0;
}