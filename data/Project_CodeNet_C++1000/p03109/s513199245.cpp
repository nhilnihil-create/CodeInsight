#include <bits/stdc++.h>
#define REP(i, n) for(long long i=0; i<n; i++)
#define REPR(i, n) for(long long i=n-1; i>=0; i--)
#define FOR(i, m, n) for(long long i=m; i<=n; i++)
#define FORR(i, m, n) for(long long i=m; i>=n; i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define VSORTR(v) sort(v.rbegin(), v.rend());
#define ALL(v) (v).begin(),(v).end()
#define FIN ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using vll = vector<ll>;
using vvll = vector<vector<ll>>;
using P = pair<ll, ll>;
const ll mod = 1e9+7;


int main(){FIN
    
    string s;cin>>s;
    int y = stoi(s.substr(0,4));
    int m = stoi(s.substr(5,2));
    int d = stoi(s.substr(8,2));
    tuple<ll,ll,ll> t = make_tuple(y,m,d);
    if (make_tuple(2019,4,30)>=t){
        cout<<"Heisei"<<endl;
        return 0;
    }
    cout<<"TBD"<<endl;
    return 0;
}