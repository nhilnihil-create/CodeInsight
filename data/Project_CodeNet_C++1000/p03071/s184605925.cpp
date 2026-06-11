#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<a+b<<endl;
    }else{
        cout<<max(a,b)*2-1<<endl;
    }

}

