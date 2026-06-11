#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string s;
    cin >> s;
    ll n;
    n=s.size();
    ll a=0,b=0;
    rep(i,n){
        if(i%2==0){
            if(s[i]=='0'){
                ++a;
            }
            else{
                ++b;
            }
        }
        else{
            if(s[i]=='1'){
                ++a;
            }
            else{
                ++b;
            }
        }
    }    

    cout << min(a,b) << endl;

    return 0;
}