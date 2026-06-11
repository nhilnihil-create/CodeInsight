#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int a,b,c,d,l,r;
int main(void){
    cin>>a>>b>>c>>d;
    l=a+b; r=c+d;
    if(l==r){
        cout<<"Balanced"<<endl;
    }else if(l<r){
        cout<<"Right"<<endl;
    }else{
        cout<<"Left"<<endl;
    }
    
}
