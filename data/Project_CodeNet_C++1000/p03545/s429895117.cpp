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
    string input; cin>>input;
    ll a[4];
    rep(i,4) a[i]=input[i]-'0';

    for(int x=0;x<8;x++){
        ll sum=a[0];
        string s;
        s+=(char)(a[0]+'0');
        for(int i=0;i<3;i++){
            if(x & (1<<i) ){
                sum+=a[i+1];
                s+='+';
                s+=(char)(a[i+1]+'0');
            }else{
                sum-=a[i+1];
                s+='-';
                s+=(char)(a[i+1]+'0');
            }
        }
        if(sum==7){
            s+="=7";
            cout<<s<<endl;
            return 0;
        }
    }
    return 0;
}