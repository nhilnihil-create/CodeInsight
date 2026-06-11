
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
    string tmp="";
    int max=0;
    for(int i=0;i<s.size();i++){
        if(s.at(i)=='A'||s.at(i)=='C'||s.at(i)=='G'||s.at(i)=='T'){
            tmp+=s.at(i);
        }else{
            if(max<tmp.size()){
                max=tmp.size();
            }
            tmp="";
        }
    }
    if(max<tmp.size()){
        max=tmp.size();
    }
    cout<<max<<endl;
}