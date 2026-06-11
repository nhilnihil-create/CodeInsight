#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0;i < n;i++)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end())
#define VRSORT(v) sort(v.rbegin(), v.rend())
#define ll long long
#define pb(a) push_back(a)
#define INF 1000000000
#define MOD 1000000007
using namespace std;
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;

typedef vector<unsigned int>vec;
typedef vector<vec> mat;
//typedef tuple<ll, ll, ll> T;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int dy[]={0, 0, 1, -1, 0};
int dx[]={1, -1, 0, 0, 0};

ll f(ll n){
    ll res=0;
    while(n>0){
        res += n%10;
        n/=10;
    }
    return res;
}
double g(ll n){
    return (double)(n)/f(n);
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    vector<ll> res;
    ll base=1;
    REP(i,15){
        for(int j=1;j<150;j++){
            res.push_back(base*(j+1) - 1);
        }
        base*=10;
    }
    VSORT(res);
    res.erase(unique(res.begin(),res.end()),res.end());

    for(ll i = 0; i < res.size(); i++)
    {
        for(ll j = i+1; j < res.size(); j++)
        {
            if(g(res[i])>g(res[j])){
                res.erase(res.begin()+i--);
                break;
            }
        }
        
    }
    ll k;
    cin>>k;
    for(ll i = 0; i < k; i++)
    {
        cout<<res[i]<<endl;
    }
    
}