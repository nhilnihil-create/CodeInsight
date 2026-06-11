#include <bits/stdc++.h>
using namespace std;
#define rep(i,ini,n) for(int i=ini;i<n;i++)

int main(){
    uint64_t x,y;
    cin>>x>>y;

    uint64_t num=0;
    while(x<=y){
        num++;
        x*=2;
    }

    cout<<num<<endl;
}