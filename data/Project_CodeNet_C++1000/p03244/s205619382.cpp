#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<cmath>
#include<cstdio>
#include<queue>
#include<deque>
#include<map>
#include<stack>
#include<set>
#include<utility>
using namespace std;
typedef pair<int,int> ii;
typedef long long ll;
typedef pair<ll,ll> p;
typedef unsigned long long int ull;
int dy[]={1,0,-1,0};
int dx[]={0,1,0,-1};
const int MAXN=100000;
const int MAXE=100000;
const int MAXV=10000;
const ll INF=2e18;
ll MOD=1e9+7;

ll power(ll a,ll x){
    ll res=1;
    while(x>0){
        if(x&1) res=res*a%13;
        a=a*a%13;
        x>>=1;
    }
    return res;
}

int main(){
    int n;cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++) cin>>v[i];
    vector<int> co(1e5+1,0),ce(1e5+1,0);
    for(int i=0;i<n;i++){
        if(i%2==0) co[v[i]]++;
        else ce[v[i]]++;
    }
    int o1,o2,e1,e2;
    o1=o2=e1=e2=-1;
    int mo=-1,me=-1;
    for(int t=0;t<2;t++){
        vector<int> cx=(t==0?co:ce);
        int& x1=(t==0?o1:e1);
        int& x2=(t==0?o2:e2);
        int& mx=(t==0?mo:me);
        for(int i=1;i<=1e5;i++){
            if(x1==-1){
                x1=cx[i];
                mx=i;
            }else if(x2==-1){
                if(x1<cx[i]){
                    x2=x1;
                    x1=cx[i];
                    mx=i;
                }else{
                    x2=cx[i];
                }
            }else if(x1<cx[i]){
                x2=x1;
                x1=cx[i];
                mx=i;
            }else if(x2<cx[i]){
                x2=cx[i];
            }
        }
    }
    if(mo!=me){
        cout<<n-(o1+e1)<<endl;
    }else{
        cout<<n-max(o1+e2,o2+e1)<<endl;
    }
    return 0;
}