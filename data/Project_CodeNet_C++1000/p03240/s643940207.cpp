#include <bits/stdc++.h> 
#define rep(i,n) for (int i = 0; i < (n); ++i)
using ll =long long;
using namespace std;
using Graph=vector<vector<int>>;
using Field=vector<string>;
using P =pair<int,int>;

const ll mod=1000000007;
const int dx[]={0,1,0,-1};
const int dy[]={1,0,-1,0};

int main(){
    int n;
    cin>>n;
    vector<int> x(n),y(n);
    vector<ll> h(n);
    rep(i,n)cin>>x[i]>>y[i]>>h[i];
    rep(j,101){
        rep(k,101){
            ll H=-1;
            rep(i,n){
                if(h[i]>0){
                    if(H==-1){
                        H=h[i]+abs(x[i]-j)+abs(y[i]-k);
                    }else{
                        ll tempH=h[i]+abs(x[i]-j)+abs(y[i]-k);
                        if(H!=tempH){
                            H=-2;
                            break;
                        }
                    }
                }
            }
            if(H==-2)continue;
            rep(i,n){
                if(h[i]==0){
                    ll tmpH=H-abs(x[i]-j)-abs(y[i]-k);
                    if(tmpH>0){
                        H=-2;
                        break;
                    }
                }
            }
            if(H==-2)continue;
            cout<<j<<" "<<k<<" "<<H<<endl;
            return 0;
        }
    }

}