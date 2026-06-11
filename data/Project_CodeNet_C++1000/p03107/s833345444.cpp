#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string s;
    cin >> s;
    int a=0,b=0;
    ll l;
    l=s.size();
    string s2;
    rep(i,l){
        s2=s[i];
        if(s2=="0"){
            ++a;
        }
        else{
            ++b;
        }
    }

    ll ans;
    ans=2*min(a,b);
    cout << ans << endl;

    

    return 0;
}