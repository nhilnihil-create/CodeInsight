#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    string s,s2,s3;
    cin >> s;
    ll n;
    n=s.size();
    ll k=0;
    ll ba=0;

    

    rep(i,n-2){
        //cout << s << endl;
        s2=s.substr(i,3);
        s3=s[i];
        
        if(s2=="ABC"){
            s[i]='B';
            s[i+1]='C';
            s[i+2]='A';
            if(ba>=1){
                s[i+1]='A';
            }
            
            ++k;
            k+=ba;
            if(ba>=1){
            --ba;
            }
            
        }
        else{
            if(s3=="A"){
            ++ba;
        }
        else{
            ba=0;
        }
        }
    }

    cout << k << endl;
    

    return 0;
}