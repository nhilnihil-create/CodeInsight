#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
#define fi first
#define se second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    int n;
    cin>>n;
    ll a[n],b[n];
    rep(i,n)cin>>a[i];
    rep(i,n)cin>>b[i];
    ll now=0;
    rep(i,n){
        if (a[i]==b[i])continue;
        else if (a[i]<b[i])now+=(b[i]-a[i])/2;
        else{
            now-=a[i]-b[i];
        }
    }
    if (now<0){
        cout<<"No"<<endl;
        return 0;
    }
    cout<<"Yes"<<endl;

    return 0;
}