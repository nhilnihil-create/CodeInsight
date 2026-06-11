#include <bits/stdc++.h>
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define pb push_back
#define mp make_pair
#define all(a) (a).begin(),(a).end()
#define riverse(v) reverse((v).begin(), (v).end())
using vi = vector<int>;
using vs = vector<string>;
using vvi = vector<vi>;
using vll = vector<ll>;
const ll MOD = 1e9+7;
vi alphabet = {'a','b','c','d','e','f','g','h','i','j','k','l','m',
               'n','o','p','q','r','s','t','u','v','w','x','y','z'};

int main() {
    int n, m;
    cin >> n >> m;
    vi pre(n+1,1);
    vvi py(m, vi(3));
    rep(i, m) {
        cin >> py[i][1];
        cin >> py[i][0];
        py[i][2] = i;
    }
    sort(py);
    vs rine(m);
    rep(i, m) {
        int x = pre[py[i][1]];
        pre[py[i][1]]++;
        string right = to_string(x);
        while (right.size() < 6) right = "0" + right;
        
        string left = to_string(py[i][1]);
        while (left.size() < 6) left = "0" + left;
        string ans = left + right;
        rine[py[i][2]] = ans;
    }
    for (string x : rine)cout << x << endl;
}