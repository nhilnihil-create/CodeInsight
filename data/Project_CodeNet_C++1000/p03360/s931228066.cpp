#include<bits/stdc++.h>
using namespace std;

int main(){

    int a,b,c,k;
    cin>>a>>b>>c>>k;
    int maxabc=max({a,b,c});
    while(k>0){
        maxabc*=2;
        k--;
    }
    cout<<a+b+c-max({a,b,c})+maxabc<<endl;

    return 0;
}