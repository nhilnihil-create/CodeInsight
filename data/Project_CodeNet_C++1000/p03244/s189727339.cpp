#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (int)(n); i++) 
#define rrep(i,n) for(int i = 1; i <= (int)(n); i++) 
#define pb push_back
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

//const ll mod = 1000000007;
//const ll INF = mod * mod;
//const double pi = 3.14159265358979;

int main() {
    int n;
    cin >> n;
    vi v(n);
    rep(i,n) cin >> v[i];
    int element_even,element_odd;
    if(n % 2 == 0) {
        element_even = n / 2;
        element_odd = n /2;
    }
    else {
        element_even = (n - 1) /2;
        element_odd = (n + 1) / 2;
    }
    vi even(100010),odd(100010);
    rep(i,n) {
        if(i % 2 == 0) odd[v[i]]++;
        else even[v[i]]++;
    }
    int max_even = 0,max_odd = 0;
    int e,o;
    rep(i,even.size()) {
        if(even[i] > max_even) {
            max_even = even[i];
            e = i;
        }
    }
    rep(i,odd.size()) {
        if(odd[i] > max_odd) {
            max_odd = odd[i];
            o = i;
        }
    }
    if(e != o) {
        //cout << max_odd << " " << max_even << endl;
        int ans = 0;
        ans += (element_even - max_even);
        ans += (element_odd - max_odd);
        cout << ans << endl;
    }
    else {
        int second_maxeven = 0;
        rep(i,even.size()) {
            if(even[i] > second_maxeven) {
                if(i == e) continue;
                else second_maxeven = even[i];
            }
        }
        int ans1 = 0;
        ans1 += (element_even - second_maxeven);
        ans1 += (element_odd - max_odd);
        int second_maxodd = 0;
        rep(i,odd.size()) {
            if(odd[i] > second_maxodd) {
                if(i == o) continue;
                else second_maxodd = odd[i];
            }
        }
        int ans2 = 0;
        ans2 += (element_odd - second_maxodd);
        ans2 += (element_even - max_even);
        cout << min(ans1,ans2) << endl;
    }
    /*
    rep(i,10) cout << odd[i] << " ";
    cout << endl;
    rep(i,10) cout << even[i] << " ";
    cout << endl;
    */
}
