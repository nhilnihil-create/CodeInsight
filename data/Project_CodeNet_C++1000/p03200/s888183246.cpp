#include <bits/stdc++.h>
#define inf 1000000005
#define mod 1000000007
#define eps 1e-10
#define rep(i,n) for(int i = 0; i < (n); ++i) 
#define rrep(i,n) for(int i = 1; i <= (n); ++i) 
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for (int i = s; i < t; ++i)
#define each(a,b) for(auto& (a): (b)) 
#define all(v) (v).begin(),(v).end() 
#define sz(v) (int)(v).size() 
#define zip(v) sort(all(v)),v.erase(unique(all(v)),v.end())
#define mx(x,y) x=max(x,y) 
#define mn(x,y) x=min(x,y)
#define rev(v) reverse((v).begin(),(v).end());
#define so(v) sort((v).begin(), (v).end());
#define yn {puts("Yes");}else{puts("No");}
#define fi first
#define se second
#define pb push_back

using namespace std;

using ll = long long;
using P = pair<int,int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using vd = vector<double>;
using vp = vector<P>;
using vs = vector<string>; 

int main() {
    int a, b;
    string s;
  	cin>>s;
    ll ct;
    a = sz(s);
    b = 0;
    ct = 0;
    rep(i, a) {
        if (s.at(i) == 'W') {
            ct = ct +i-b;
            b++;
        }
    }
    cout << ct << endl;
    return 0;
}
