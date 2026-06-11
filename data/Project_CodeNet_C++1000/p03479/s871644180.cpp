#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
    ll x,y;
    cin>>x>>y;
    ll a=x;//初項
    int count=0;
    while(1){
        if(a>y)break;
        count++;
        a=a*2;
    }

    cout<<count<<endl;
}