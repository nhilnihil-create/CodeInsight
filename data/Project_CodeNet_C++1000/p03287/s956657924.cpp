#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG

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

const double pi=3.141592653589793;

int main() {
    ll n,m;
    cin>>n>>m;
    ll a[n];
    rep(i,n){
        cin>>a[i];
        //cout<<a[i]<<endl;
    }
    vll s;
    ll now=0;
    s.push_back(0);
    rep(i,n){
        now+=a[i];
        now%=m;
        s.push_back(now);
        //cout<<s[i+1]<<endl;
    }
    sort(s.begin(),s.end());
    ll ans=0;
    now=s[0];
    ll count=1;
    for (int i=1;i<n+1;i++){
        if (now!=s[i]){
            now=s[i];
            ans+=(count)*(count-1)/2;
            count=1;
        }
        else{
            count+=1;
        }
    }
    ans+=(count)*(count-1)/2;
    //ans%=m;
    cout<<ans<<endl;


    

    return 0;
}
