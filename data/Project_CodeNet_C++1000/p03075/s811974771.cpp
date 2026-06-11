#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c,d,e,k;
    cin>>a>>b>>c>>d>>e>>k;
    if(b-a<=k && c-a<=k && d-a<=k && e-a<=k && c-b<=k && d-b<=k && d-c<=k && e-b<=k && e-c<=k && e-d<=k )
      cout<<"Yay!";
    else
        cout<<":(";
}

