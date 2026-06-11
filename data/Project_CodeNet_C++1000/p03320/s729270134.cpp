#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<set>
#include<map>
#include<deque>
using namespace std;
#define rep(i,n) for(int i=1;i<=(int)n;i++)
#define Rep(i,n) for(int i=0;i<=(int)(n-1);i++)
#define REP(i,b,e) for(int i=b;i<(int)e;i++)
typedef long long ll;
typedef map<ll,ll> mll;
typedef vector<ll> vll;
ll INF=1e18;
int inf=1e9+1000;
 
string alpha="abcdefghijklmnopqrstuwvxyz";

int K;

ll pow(ll n){
    if(n==0) return 1;
    else if(n%2==0) return pow(n/2)*pow(n/2);
    else return 10*pow(n/2)*pow(n/2);
}

ll keta(ll n){
    for(int i=16;i>=0;i--){
        if(n/pow(i)>0){
            return i+1;
        }
    }
    return -1;
}

ll S(ll n){
    ll ret=0;
    for(int i=16;i>=0;i--){
        ret+=n/pow(i);
        n-=((n/pow(i))*pow(i));
    }
    return ret;
}

deque<ll> ans;

int main(){
    cin>>K;
    ll bgn=10e15;
	bgn-=1;
    ll n=bgn;
    ans.push_front(n);
    ll k=keta(bgn)-4;
    bgn-=pow(k);
    while(bgn>=1){
        if(S(n)*bgn<=n*S(bgn)){
            ans.push_front(bgn);
            n=bgn;
        }
        k=keta(bgn)-4;
        if(k>=0){
            bgn-=pow(k);
        }
        else bgn-=1;
    }
    Rep(i,K){
        if(i!=(K-1)){
            cout<<ans[i]<<" ";
        }
        else cout<<ans[i]<<endl;
    }

    return 0;
}