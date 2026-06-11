#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int a,b;
    cin>>a>>b;
    if(b>=a)cout<<a;
    else {
        if(a==1)cout<<1;
        else cout<<a-1;
    }
}
