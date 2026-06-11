#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long;
int main()
{
    int n;
    cin>>n;
    pair<pair<string,int>,int> p[n];
    rep(i,n){
        cin>>p[i].first.first>>p[i].first.second;
        p[i].first.second*=-1;
        p[i].second=i+1;
    }
    sort(p,p+n);
    rep(i,n) cout<<p[i].second<<endl;
}