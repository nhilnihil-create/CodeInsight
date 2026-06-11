#include <bits/stdc++.h>
using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
//const int mod=998244353;
using P = pair<int,int>;
using Pll = pair<ll,ll>;
using ld=long double;
using V=vector<int>;
using Vl=vector<ll>;
using VV=vector<vector<int>>;
using VVl=vector<vector<ll>>;

int main(){
    ll n,k;cin >>n>>k;
    string s;cin >>s;
    int key=1;
    V run;
    int now=0;
    for (int i = 0; i < n; ++i) {
        int tmp=(s[i]-'0');
        if(tmp==key){
            now++;
        }
        else {
            run.push_back(now);
            now=1;
            key=1-key;
        }
    }
    run.push_back(now);
    if(run.size()%2==0){
        run.push_back(0);
    }
    int m=run.size();
    Vl sum(m+1,0);
    for (int i = 0; i < m; ++i) {
        sum[i+1]=sum[i]+run[i];
    }
    ll ans=-1;
    for (int i =1; i <=m;i+=2) {
        ll res=sum[min(i+2*k,(ll)m)]-sum[i-1];
        ans=max(ans,res);
//        cout <<i<<" "<<res<<" ";
    }
//    cout <<endl;
    cout <<ans <<endl;
}

