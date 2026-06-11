#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define co(x) cout << (x) << "\n"
#define cosp(x) cout<< (x) << " "

int main(){
    int a,b,k;cin>>a>>b>>k;
    map<int,int>mp;
    rep(i,k){
        mp[min(b,a+i)]++;
    }
    rep(i,k){
        mp[max(a, b-i)]++;
    }
    for(auto i=mp.begin();i!=mp.end();i++){
        co(i->first);
    }
}