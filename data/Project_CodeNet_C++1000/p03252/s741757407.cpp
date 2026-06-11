#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string s,t;
    cin >> s >> t;
    map <string,int> ms,mt;
    int ans=0;
    ll n;
    n=s.size();
    string ss,tt;
    rep(i,n){
        ss=s[i];
        tt=t[i];
        ++ms[ss];
        ++mt[tt];
        if(ms[ss]!=mt[tt]){
            ans=1;
            break;
            
        }
    }

    if(ans==0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }

    

    return 0;
}