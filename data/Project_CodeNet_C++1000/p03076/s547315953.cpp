#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    vector <int> a(5);
    rep(i,5){
        cin >> a[i];
    }

    int ans=0,m=10,m2,m3;
    rep(i,5){
        if(a[i]%10==0){
            ans+=a[i];
        }
        else{
            m2=a[i]%10;
            m=min(m,m2);
            ans+=(a[i]/10+1)*10;
        }
    }

    if(m==10){
        cout << ans << endl;
    }
    else{
    ans+=m-10;
    cout << ans << endl;
    }

    

    return 0;
}