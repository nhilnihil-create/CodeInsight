#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
const ll mod =1000000007;
int main(){
    long long x,y;
    cin>>x>>y;
    int count =0;
    while(x<=y){
        x *=2;
        count++;
    }
    cout<<count<<endl;
}