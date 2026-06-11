#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using P = pair<int,int>;
using ll = long long; 

int main(){
    string s;
    cin>>s;

    ll ans=0;
    ll max=0;
    rep(i,s.size()){
        if(s[i]=='A' || s[i]=='C' || s[i]=='G' || s[i]=='T' ){ans++;}
        else{
            max=std::max(max,ans);
            ans=0;
        }
    }
    max=std::max(max,ans);

    cout<<max<<endl;


}

