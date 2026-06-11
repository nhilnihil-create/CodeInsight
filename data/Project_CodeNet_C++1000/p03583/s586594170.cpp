#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = int64_t;
using P = pair<ll,ll>;
ll INF = 1000000007;
// ll INF = 9223372036854775807;
// ll INF = 998244353;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    ll n;
    cin >> n;
    ll resh=0, resw=0, resn=0;
    for(ll h=1; h<=3500; h++){
        for(ll w=h; w<=3500; w++){
            if(4*h*w-n*(h+w)==0 || 4*h*w-n*(h+w)<0) continue;
            if((n*h*w)%(4*h*w-n*(h+w))==0){
                resh = h;
                resw = w;
                resn = (n*h*w)/(4*h*w-n*(h+w));
                break;
            }
        }
        if(resh!=0) break;
    }
    cout << resh << " " << resw << " "  << resn << endl;
}