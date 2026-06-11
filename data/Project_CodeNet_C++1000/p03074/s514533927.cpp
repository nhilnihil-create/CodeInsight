#include <bits/stdc++.h>
#define REP(i, n) for(long long i = 0; i < n; i++)
#define REPR(i, n) for(long long i = n - 1; i >= 0; i--)
#define FOR(i, m, n) for(long long i = m; i <= n; i++)
#define FORR(i, m, n) for(long long i = m; i >= n; i--)
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
    
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;

    if(s[0]=='0')k--;
    int m=0,p=0;
    vector<int>x(1,-1);
    for(int i=0;i<n;i++){
        if(k<0){
            k++;
            p++;
        }
        if(s[i]=='1' && s[i+1]=='0') k--;
        if(s[i]=='0' && s[i+1]=='1') x.push_back(i);
        m=max(m,i-x[p]);
    }
    cout<<m<<endl;
    return 0;
}