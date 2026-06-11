#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    int a,b; cin>>a>>b;
    if(b%a==0){
        cout<<a+b<<endl;
    }else{
        cout<<b-a<<endl;
    }

}

