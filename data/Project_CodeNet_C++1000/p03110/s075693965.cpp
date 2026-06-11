#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    int n;
    cin >> n;
    ll x1,t1=0;
    double x2,t2=0;
    string s;
    rep(i,n){
        cin >> x2;
        cin >> s;
        if(s=="JPY"){
            t1+=x2;
        }
        else{
            //cin >> x2;
            t2+=x2;
        }
    }

    double ans=0;
    ans=t1+t2*380000;

    printf("%.10f",ans);

    

    return 0;
}