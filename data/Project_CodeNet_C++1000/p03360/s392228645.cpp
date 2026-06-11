#include<bits/stdc++.h>
using namespace std;

int main(){

    int a,b,c,k;
    cin>>a>>b>>c>>k;
    int tk=1;
    while(k>0){
        tk*=2;
        k--;
    }
    cout<<a+b+c+(tk-1)*max({a,b,c})<<endl;

    return 0;
}