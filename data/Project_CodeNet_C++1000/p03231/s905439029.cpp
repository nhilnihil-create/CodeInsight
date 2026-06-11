#include <iostream>
#include <algorithm>
#include <vector>
#include <limits.h>
#include <cmath>
#include <map>
#include <iomanip>
using namespace std;
using ll=long long;
int gcd(int a,int b){
    if(a%b==0)return b;
    return gcd(b,a%b);
}
ll lcm(int a,int b){
    return (long long)a*(long long)b/gcd(a,b);
}
int main(){
    int a,b;
    cin>>a>>b;
    string s,t;
    cin>>s>>t;
    int na=0,nb=0;
    int g=gcd(a,b);
    int n=a/g,m=b/g;
    for(int i=0;i<g;i++){
        if(s[na]!=t[nb]){
            cout<<-1<<endl;
            return 0;
        }
        na+=n;
        nb+=m;
    }
    cout<<lcm(a,b)<<endl;
}
