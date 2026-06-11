#include <bits/stdc++.h>
using namespace std;
 
int main(){
    long long n,m;
    cin>>n>>m;
    string str,t;
    cin>>str>>t;
    long long g=__gcd(n,m);
    long long l=n/g*m;
    bool flag=true;
    n/=g;
    m/=g;
    for(long long i=0;i<g;i++){
        if(str[i*n]!=t[i*m]){
            flag=false;
            break;
        }
    }
    if(flag) 
      cout<<l;
    else 
      cout<<-1;
  return 0;
}