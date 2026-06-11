#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

ll ka(int si){
    ll ans3=1;
    rep(i,si){
        ans3*=2;
    }
    return ans3;
}

int main(){
    ll a,b;
    cin >> a >> b;
    if(a!=0){
    --a;
    }
    vector <ll> b3(50,0),b2(50,0);
    vector <ll> a3(50,0),a2(50,0);

    rep(i,50){
        a3[i]=(a>>i)&1;
        b3[i]=(b>>i)&1;
        //cout << b3[i] << endl;
    }
    ll k,k2;
    int y;

    rep(i,50){
        k=ll(ka(i));
        rep(j,i+1){
            if(b3[i-j]==0){
                k-=ll(ka(i-j));
            }
        }
        if(k<0){
            k=0;
        }
        b>>=1;
        
        b2[i]=b*ll(ka(i));
        b2[i]+=k;
        if(b==0){
            y=i;
            break;
        }
    }
    rep(i,y+1){
        k=ll(ka(i));
        rep(j,i+1){
            if(a3[i-j]==0){
                k-=ll(ka(i-j));
            }
        }
        if(k<0){
            k=0;
        }
        a>>=1;
        
        a2[i]=a*ll(ka(i));
        a2[i]+=k;
        if(a==0){
            
            break;
        }
        
    }

    
    

    vector <int> ans(50,0);
    rep(i,50){
        //cout << a2[i]  << " " << b2[i] << endl;
        b2[i]-=a2[i];
        if(b2[i]%2==1){
        ans[i]=1;
        }
    }

    ll ans2;
    ans2=0;
    rep(i,y+1){
        if(ans[i]==1){
        ans2+=ll(ka(i));
        }
    }

    cout << ans2 << endl;


    return 0;
}