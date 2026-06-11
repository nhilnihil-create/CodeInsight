#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define PI 3.14159265359
#define INF 1000100100
#define MOD 1000000007
#define all(x) (x).begin(),(x).end()
typedef long long ll;
#define P pair<ll, ll>
#define PP pair<P,int>
#define T tuple<int,int,int> 
using namespace std;

vector<ll> divisor(ll a){
    vector<ll> res;
    for(int i=2; i<=sqrt(a); i++){ //1を含んでいない
        if(a%i==0){
            res.push_back(i);
            if(i!=a/i) res.push_back(a/i);
        }
    }
    res.push_back(a);
    sort(all(res));
    reverse(all(res));
    return res;
}

int main(){
    ll n,m; cin >> n >> m;
    vector<ll> re;
    re=divisor(m);
    rep(i,re.size()){
        if(m-re[i]*n>=0 && (m-re[i]*n)%re[i]==0){
            cout << re[i] << endl;
            return 0;
        }
    }
    cout << 1 << endl;
return 0;
}
