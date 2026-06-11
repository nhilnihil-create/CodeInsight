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
    string s;
    cin>>s;
    bool f=false;
    if(s.at(5)=='0'){
        if(s.at(6)=='1' || s.at(6)=='2' || s.at(6)=='3' ||s.at(6)=='4'){
            f=true;
        }
    }
    if(f){
        cout<<"Heisei"<<endl;
    }else{
        cout<<"TBD"<<endl;
    }
}