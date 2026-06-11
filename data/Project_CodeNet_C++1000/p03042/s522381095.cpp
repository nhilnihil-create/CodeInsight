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
    int prev,next;
    prev=10*(int)(s.at(0)-'0')+(int)(s.at(1)-'0');
    next=10*(int)(s.at(2)-'0')+(int)(s.at(3)-'0');
    if((prev>12 ||prev<=0 )&& (next>12 || next<=0)){
        cout<<"NA"<<endl;
    }else if((prev>12 || prev<=0) && (next<=12 && next>0)){
        cout<<"YYMM"<<endl;
    }else if((next>12 || next<=0)&& (prev<=12 && prev>0)){
        cout<<"MMYY"<<endl;

    }else{
        cout<<"AMBIGUOUS"<<endl;
    }
}
