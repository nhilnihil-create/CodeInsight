#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n,m,c;
    cin >> n >> m >> c;
    int ans=0;
    vector <int> b(m),a(m);
    rep(i,m){
        cin >> b[i];
    }

    int ans2;
    rep(i,n){
        ans2=0;
        rep(i,m){
            cin >> a[i];
            ans2+=a[i]*b[i];
        }
        if((ans2+c)>0){
            ++ans;
        }
    }

    cout << ans << endl;

    

    return 0;
}