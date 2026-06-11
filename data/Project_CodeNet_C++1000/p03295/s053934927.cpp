#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n,m;
    cin >> n >> m;
    vector <vector <int>> y(m,vector <int> (2));
    int a,b;
    rep(i,m){
        cin >> a >> b;
        y[i][0]=a;
        y[i][1]=b;
    }

    sort(y.begin(),y.end());
    int ans=0;
    if(m>=1){
        ++ans;
    }

    int r,l;
    rep(i,m){
        //cout << y[i][0] << y[i][1] << endl;
        if(i==0){
            l=y[0][0];
            r=y[0][1];
        }
        else{
            if(y[i][0]>=r){
                ++ans;
                l=y[i][0];
                r=y[i][1];
            }
            else{
                l=y[i][0];
                r=min(r,y[i][1]);
            }
        }
    }

    cout << ans << endl;
    

    return 0;
}