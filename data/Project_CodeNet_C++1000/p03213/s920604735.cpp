#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    int n;cin >>n;
    ll cnt5=0;
    ll cnt3=0;
    ll cnt15=0;
    ll cnt25=0;
    ll cnt75=0;
    unordered_map<int,int>mp;
    for (int i = 1; i <=n; ++i) {
        int c=i;
        for(int j=2;j*j<=c;j++){
            while(c%j==0){
                mp[j]++;
                c/=j;
            }
        }
        if(c!=1)mp[c]++;
    }
    for(auto p:mp){
        if(p.second>=74)cnt75++;
        if(p.second>=2)cnt3++;
        if(p.second>=4)cnt5++;
        if(p.second>=14)cnt15++;
        if(p.second>=24)cnt25++;
    }
//    cout <<cnt3<<" "<<cnt5<<" "<<cnt15<<" "<<cnt25<<" "<<cnt75<<endl;
    ll ans=0;
    ans+=cnt75;
    ans+=(cnt3>0)?(cnt3-1)*cnt25:0;
    ans+=(cnt5>0)?(cnt5-1)*cnt15:0;
    ans+=(cnt3>1)?(cnt3-2)*((cnt5-1)*cnt5)/2:0;
    cout <<ans <<endl;
    return 0;
}
