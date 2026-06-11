//C - Multiple Gift
#include<iostream>

using namespace std;

typedef long long ll;

int main(){
    ll x,y,cnt=1;

    cin>>x>>y;
    while(1){
        x=x*2;
        if(x>y){ break; }
        cnt++;
    }
    cout<<cnt<<endl;

    return 0;
}