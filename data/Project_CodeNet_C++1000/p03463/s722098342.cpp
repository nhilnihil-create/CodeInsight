#include<iostream>
#include<cstring>
using namespace std;
int main(){
    int n,x,y;cin>>n>>x>>y;
    string ans=(y-x)%2?"Borys":"Alice";
    cout<<ans;
    return 0;
}