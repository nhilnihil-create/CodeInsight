#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n;
    cin>>n;
    vector<int>x(n),y(n),h(n);
    rep(i,n)cin>>x[i]>>y[i]>>h[i];
    rep(dy,101){
        rep(dx,101){
            int nh=-1;
            rep(i,n){
                if(h[i]>0){
                    int tmp=h[i]+abs(dy-y[i])+abs(dx-x[i]);
                    if(nh==-1)nh=tmp;
                    else{
                        if(nh!=tmp){
                            nh=-2;
                            break;
                        }
                    }
                }
            }
            if(nh==-2)continue;
            rep(i,n){
                if(h[i]==0){
                    int dist=abs(dy-y[i])+abs(dx-x[i]);
                    if(nh>dist){
                        nh=-2;
                        break;
                    }
                }
            }
            if(nh==-2)continue;
            cout<<dx<<" "<<dy<<" "<<nh<<endl;
            return 0;
        }
    }
}