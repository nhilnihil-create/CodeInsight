#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
using ll=long long int;

int main(){
    long double n,total;
    cin>>n;
    total=0;
    rep(i,n){
        string s;
        long double a;
        cin>>a>>s;
        if(s=="JPY")total+=a;
        else total+=a*380000.0;

    }
    cout<<fixed<<setprecision(18)<<total<<endl;
}