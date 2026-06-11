#include<bits/stdc++.h>
using namespace std;

long long x,y,a;

int main () {
    cin>>x>>y;
    while(x<=y){
        x=x*2;
        a++;
    }
    cout<<a<<endl;
}