#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
ll n;
ll M=1000000007;
int main(void){
    int a,b;
    cin>>a>>b;
    if(a+b==15){
        cout<<"+"<<endl;
    }else if(a*b==15){
        cout<<"*"<<endl;
    }else{
        cout<<"x"<<endl;
    }
    
}
