#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    string s;
    cin >> s;
    int n = s.size();


    vector<char> v;
    rep(i, n){
        if (s[i] != 'x') v.push_back(s[i]);
    }




    int m = v.size();
    if (m == 0){
        cout << 0 << endl;
        return 0;
    }
    
    
    
    bool flag = true;
    rep(i, (m + 1) / 2){
        if (v[i] != v[m-i-1]) flag = false; 
    }

    if (!flag){
        cout << -1 << endl;
        return 0;
    }

    // rep(i, v.size()) cout << v[i] << " ";
    // cout << endl;

    vector<char> l, r;
    int i = 0, c = 0;
    while (i < n){
        l.push_back(s[i]);
        if (s[i] == v[c]) c++;
        if (c == (m + 1) / 2) break;
        i++;
    }
    int j = n-1;
    c = 0;
    while (j >= 0){
        r.push_back(s[j]);
        if (s[j] == v[c]) c++;
        if (c == (m + 1) / 2) break;
        j--;
    }

    // rep(i, l.size()) cout << l[i] << " ";
    // cout << endl;
    // rep(i, r.size()) cout << r[i] << " ";
    // cout << endl;

    i = 0, j = 0;
    ll ans = 0;
    while (i < l.size() && j < r.size()){
        if (l[i] == 'x' && r[j] != 'x'){
            ans++;
            i++;
        }
        else if (l[i] != 'x' && r[j] == 'x'){
            ans++;
            j++;
        }
        else {
            i++;
            j++;
        }
    }
    cout << ans << endl;

    return 0;
}