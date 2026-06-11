#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int a,b,x;
    cin>>a>>b>>x;
    if(a>x){
        cout<<"NO"<<endl;
    }
    else if(a+b>=x){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    return 0;
}