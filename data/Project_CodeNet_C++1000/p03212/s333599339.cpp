#include<bits/stdc++.h>
using namespace std;

#define REP(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main() {
    set<ll> a;
    
    vector<ll> b;
    b.push_back(3);
    b.push_back(5);
    b.push_back(7);
    
    int c[3];
    c[0]=3,c[1]=5,c[2]=7;
    
    ll tmp=0;
    ll m = b.size();
    
    while(tmp<999999999){
        m = b.size();
        rep(i,m){
            rep(j,3){
                tmp = b[i]*10 + c[j];
                b.push_back(tmp);
            }
        }
    }
    
    sort(b.begin(),b.end());
    ll n;cin>>n;
    
    m = b.size();
    
    int d[3];
    vector<ll> e;

    b.push_back(0);
    rep(i,m){
        rep(j,3) d[j]=0;
        if(b[i]!=b[i+1]){
        
        tmp = b[i];
        while(tmp>0){
          ll res = tmp%10;
            if(res == 3)++d[0];
            if(res == 5)++d[1];
            if(res == 7)++d[2];
          tmp/=10;
          if(tmp==0)break;
        }
//    cout<<b[i]<<" "<<d[0]<<" "<<d[1]<<" "<<d[2]<<endl;
        ll res2 = d[0]*d[1]*d[2];
        if(res2 != 0)e.push_back(b[i]);
        }
    }

   ll ans = 0;
    m = e.size();
    rep(i,m){
        if(e[i]<=n && e[i]!=e[i+1])++ans;
        if(e[i]>n)break;
    }
    cout<<ans<<endl;
	return 0;
}