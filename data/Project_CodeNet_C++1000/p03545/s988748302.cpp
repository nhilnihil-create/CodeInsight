#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rep2(i,s,n) for(int i = (s); i < (n); ++i)
#define ll long long
#define ld long double
#define P pair<ll,ll>
#define all(v) v.begin(),v.end()

const ll mod = 1e9+7;
const ll INF = 1e18;
const double pi = acos(-1.0);

int main(void)
{
    string a; cin>>a;
    rep(i,4) a[i]-='0';
    for(int i=0;i<(1<<3);i++){
        ll sum=a[0];
        string t;
        t += (char)(a[0]+'0');
        for(int j=0;j<3;j++){
            if(i & (1<<j)){
                sum+=a[j+1];
                t+='+';
                t+=(char)(a[j+1]+'0');
            }else{
                sum-=a[j+1];
                t+='-';
                t+=(char)(a[j+1]+'0');
            }
        }
        if(sum==7){
            t+="=7";
            cout<<t<<endl;
            return 0;
        }
    }
    return 0;
}