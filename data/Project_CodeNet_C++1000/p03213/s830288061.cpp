#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    ll n;cin>>n;
    map<int,int> mp,mp2;
    for(int i=2;i<=n;i++){
        int x=i;
        for(int j=2;j<=sqrt(x);j++){
            while(x%j==0){
                mp[j]++;
                x/=j;
            }
        }
        if(x>1)mp[x]++;
    }
    for(auto p:mp){
        ll x=p.second;
        rep(i,x+1)mp2[i]++;
    }
    ll res=0;
    res+=mp2[74];
    res+=(mp2[4]*(mp2[4]-1)*(mp2[2]-2))/2;
    //cout<<res<<endl;
    res+=(mp2[2]-1)*mp2[24];
    res+=mp2[14]*(mp2[4]-1);
    cout<<res<<endl;
}