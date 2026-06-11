#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define inf 1001001001001001001
#define mod 1000000007
#define mod2 998244353
#define pi acos(-1)
#define all(v) v.begin(),v.end()

int main(){
    string s;cin>>s;
    int ans=753;
    rep(i,s.size()-2){
        string str="";
        str+=s.at(i);
        str+=s.at(i+1);
        str+=s.at(i+2);
        int x=stoi(str);
        if(abs(x-753)<ans){
            ans=abs(x-753);
        }
    }
    cout<<ans<<endl;
}