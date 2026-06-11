#include<bits/stdc++.h>

#define REP(i,a,b) for(int i=a;i<=b;++i)
typedef long long ll;

using namespace std;

void File(){
    freopen("ARC99D.in","r",stdin);
    freopen("ARC99D.out","w",stdout);
}

double cal(ll x){
    ll y=10,len=1,sum=0,ret=x;
    while(y<=x)y=(y<<1)+(y<<3),++len;
    while(len--){
        y/=10;
        sum+=x/y;
        x%=y;
    }
    return ret*1.0/sum;
}

bool judge(ll x){
    ll a=1;
    while(a<=x){
        if(cal(x+a)<cal(x))return false;
        a=(a<<1)+(a<<3);
    }
    return true;
}

ll k,now;


int main(){
    cin>>k;
    while(k--){
        ll a=1;
        while(true){
            if(judge(now+a)){
                now+=a;
                break;
            }
            a=(a<<1)+(a<<3);
        }
        cout<<now<<endl;
    }
    return 0;
}