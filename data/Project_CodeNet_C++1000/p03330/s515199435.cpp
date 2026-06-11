#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
#include <set>
using namespace std;
using ll = long long;
using Lf = long double;
using plong = pair<ll,ll>;
const int mod = 1000000007;

int main(){
    ll N,C;cin>>N>>C;
    ll D[C][C];
    for(ll i=0;i<C;i++){
        for(ll j=0;j<C;j++){
            cin>>D[i][j];
        }
    }
    ll c[N][N];
    for(ll i=0;i<N;i++){
        for(ll j=0;j<N;j++){
            cin>>c[i][j];
        }
    }
    vector<vector<ll>> color(C,vector<ll>(3,0));
    for(ll i=0;i<C;i++){
        for(ll x=0;x<N;x++){
            for(ll y=0;y<N;y++){
                if((x+y)%3==0){
                    color[i][0]+=D[c[x][y]-1][i];
                }else if((x+y)%3==1){
                    color[i][1]+=D[c[x][y]-1][i];
                }else{
                    color[i][2]+=D[c[x][y]-1][i];
                }
            }
        }
    }    
    // for(ll i=0;i<C;i++){
    //     for(ll j=0;j<3;j++){
    //         cout<<", color:"<<i<<", mod:"<<j<<", cost:"<<color[i][j];
    //     }
    //     cout<<endl;
    // }
    ll res=999999999999;
    for(ll i=0;i<C;i++){
        for(ll j=i+1;j<C;j++){
            for(ll k=j+1;k<C;k++){
                for(ll o=0;o<6;o++){
                    ll zero,one,two;
                    switch (o)
                    {
                    case 0:
                        zero = i;one = j;two = k;
                        break;
                    case 1:
                        zero = i;one = k;two = j;
                        break;
                    case 2:
                        zero = j;one = i;two = k;
                        break;
                    case 3:
                        zero = j;one = k;two = i;
                        break;
                    case 4:
                        zero = k;one = j;two = i;
                        break;
                    case 5:
                        zero = k;one = i;two = j;
                        break;
                    default:
                        break;
                    }
                    ll tmp=color[zero][0]+color[one][1]+color[two][2];
                    res = min(res,tmp);
                    // cout<<tmp<<endl;
                }
            }
        }
    }
    cout<<res<<endl;
}