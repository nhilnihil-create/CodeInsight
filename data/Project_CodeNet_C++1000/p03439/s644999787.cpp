#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
    ll n;
    cin >> n;
    ll l = 0, r = n;

    cout << l << endl;
    string t, u = " ";
    cin >> t;
    if (t == "Vacant") exit;
    else u = t;

    while (r - l  > 1){
        ll y = (l + r) / 2;
        cout << y << endl;
        string s;
        cin >> s;
        if (s == "Vacant") break;
        else{
            if (((y - l + 1) % 2 == 0 && u != s) || ((y - l + 1) % 2 != 0 && u == s)){
                l = y;
                u = s;
            }
            else r = y;
        }
    }
}