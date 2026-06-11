#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    vector <int> ans(11);
    ans[0]=c;
    rep(i,10){
        ans[i+1]=ans[i]*a-b;
    }
    rep(i,10){
        cout << ans[i+1] << endl;
    }
    

    return 0;
}