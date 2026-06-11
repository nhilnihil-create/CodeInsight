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
    bool flag=true;
    if(s.at(0)!='A'){
        flag=false;
    }
    int Ccount=0;
    int Cpoint=0;
    for(int i=2;i<s.size()-1;i++){
        if(s.at(i)=='C'){
            Ccount++;
            Cpoint=i;
        }
    }
    if(Ccount!=1){
        flag=false;
    }
    rep(i,s.size()){
        if(i==0 || i==Cpoint){
            continue;
        }else{
            if(!islower(s.at(i))){
                flag=false;
            }
        }
    }
    if(flag)cout<<"AC"<<endl;
    else cout<<"WA"<<endl;

}