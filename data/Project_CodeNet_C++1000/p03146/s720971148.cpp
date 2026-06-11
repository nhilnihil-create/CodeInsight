#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define ll long long
#define P pair<ll,ll>
#define all(v) (v).begin(),(v).end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    ll s; cin>>s;
    set<ll> st;
    ll x=s;
    while(st.count(x)==0){
        st.insert(x);
        if(x%2==0) x/=2;
        else x=3*x+1;
    }
    cout<<st.size()+1<<endl;
    return 0;
}