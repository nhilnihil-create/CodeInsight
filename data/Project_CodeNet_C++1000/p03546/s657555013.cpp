#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int h,w;
    cin >> h >> w;
    //vector <int> ans(10,100000);
    //ans[1]=0;
    vector <vector <int>> c(10,vector <int> (10)),ans(10,vector <int> (10,100000));

    ans[1][1]=0;
    rep(i,10){
        rep(j,10){
            cin >> c[i][j];
        }
    }

    rep(i,10){
        rep(j,10){
            rep(k,10){
                c[j][k]=min(c[j][k],c[j][i]+c[i][k]);
            }
        }
    }

   /* rep(i,10){
        rep(j,10){
            cout << c[i][j];
        }
        cout << endl;
    }*/


int x;
ll ans2=0;
    rep(i,h*w){
        cin >> x;
        if(x!=-1){
        ans2+=c[x][1];
        }
    }

    cout << ans2 << endl;
    

    return 0;
}