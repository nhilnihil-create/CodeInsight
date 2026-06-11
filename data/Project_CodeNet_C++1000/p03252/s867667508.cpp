//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for(int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
using namespace std;
using Graph = vector<vector<int>>;
typedef long long ll;
const int mod= 1e+9+7;
ll INF=1e10;

int main(){
    string s,t; cin>>s>>t;
    ll n=s.size();
    for(char c='a';c<='z';c++){
        rep(j,n){
            if(s[j]==c){
                char cs=s[j],ct=t[j];
                for(ll k=j;k<n;k++){
                    if(s[k]==cs&&t[k]!=ct){
                        cout<<"No"<<endl;
                        return 0;
                    }
                    else if(s[k]!=cs&&t[k]==ct){
                        cout<<"No"<<endl;
                        return 0;
                    }
                }
                break;
            }
        }
    }
    cout<<"Yes"<<endl;
}

























































































