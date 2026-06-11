#include <bits/stdc++.h>
#define rep(i, s, n) for (int i = (s); i < (int)(n); i++)
#define per(i, n, s) for (int i = (n-1); i >= (int)(s); i--)
#define all(x) (x).begin(),(x).end()
#define debug(x) cout<<#x<<": "<<x<<endl
using namespace std;
using ll = long long;
const ll MOD = 1e9+7;
const ll LINF = LLONG_MAX;
const int INF = INT_MAX;

int main(){
    int n,t; cin>>n>>t;
    vector<int> v;
    rep(i,0,n){
        int x,y;
        cin>>x>>y;
        if(y<=t) v.push_back(x);
    }
    if(v.size()==0){
        cout<<"TLE"<<endl;
        return 0;
    }
    sort(all(v));
    cout<<v[0]<<endl;
    return 0;
}