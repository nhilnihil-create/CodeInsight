//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;
ll INF=1e10;

int main(){
    ll n,m; cin>>n>>m;
    vector<vector<ll>>a(m,vector<ll>(3));
    rep(i,m){
        cin>>a[i][0]>>a[i][1];
        a[i][2]=i+1;
    }
    sort(a.begin(),a.end());
    vector<vector<ll>>na(m,vector<ll>(3));
    ll cnt=1;
    rep(i,m){
        na[i][0]=a[i][2];
        na[i][1]=a[i][0];
        na[i][2]=cnt;
        if(i<=m-2&&a[i+1][0]==a[i][0])cnt++;
        else cnt=1;
    }
    sort(na.begin(),na.end());
    rep(i,m){
        string s=to_string(na[i][1]);
        string t=to_string(na[i][2]);
        rep(j,6-s.size())cout<<'0';
        cout<<s;
        rep(j,6-t.size())cout<<'0';
        cout<<t<<endl;
    }
}

























































































