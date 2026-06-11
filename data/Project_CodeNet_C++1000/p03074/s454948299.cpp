#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int(i)=0;i<(n);i++)
typedef long long ll;

int main(){
    int n,k;string ss;cin>>n>>k>>ss;
    vector<ll> a,s(1,0);

    int count=1;
    for(int i=1;i<n;i++){
        if(ss.at(i-1)!=ss.at(i)){
            a.push_back(count);
            count=1;
        }else count++;
    }
    a.push_back(count);

    int na=a.size();
    REP(i,na) s.push_back(s.at(i)+a.at(i));

    ll ans=0;
    for(int i=ss.at(0)-'0'-1;i<na;i+=2){
        int l=max(0,i),r=min(i+2*k+1,na);
        ans=max(ans,s.at(r)-s.at(l));
    }
    cout<<ans;
}