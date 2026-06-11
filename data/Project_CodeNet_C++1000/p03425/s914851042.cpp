#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main(void)
{
    int n;
    cin>>n;
    vector<ll> s(5);
    rep(i,0,n){
        string str;
        cin>>str;
        if(str[0]=='M')s[0]++;
        else if(str[0]=='A')s[1]++;
        else if(str[0]=='R')s[2]++;
        else if(str[0]=='C')s[3]++;
        else if(str[0]=='H')s[4]++;
    }
    
    ll ans=0;
    rep(i,0,5){
        rep(j,i+1,5){
            rep(k,j+1,5){
                ans+=s[i]*s[j]*s[k];
            }
        }
    }
    printf("%lld\n",ans);
    return 0;
}