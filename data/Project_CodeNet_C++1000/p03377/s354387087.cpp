#include<bits/stdc++.h>
using namespace std;
int main (){
    int x,a,b;
    cin>>a>>b>>x;

    if( a<= x ){
            if(a+b>=x)cout<<"YES";
            else cout<<"NO";
    }
    else cout<<"NO";
    return 0;
}

