#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=1005;
int main(){
    ios_base:: sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    string s;cin>>s;
    ll k;cin>>k;
    ll n=s.size();
    set<string> a;
    if(n<=50){
        for(ll i=0;i<n;i++){
            string cur="";
            for(ll j=i;j<n;j++)cur+=s[j],a.insert(cur);
        }
    }
    else{
        for(ll i=0;i<n;i++){
            string cur="";
            for(ll j=i,len=1;len<=k&&j<n;j++,len++)cur+=s[j],a.insert(cur);
        }
    }

    for(;k>0;k--)s=(*a.begin()),a.erase(a.begin());
    cout<<s;
}
