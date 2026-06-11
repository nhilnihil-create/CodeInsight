#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <numeric>
using namespace std;
typedef long long ll;

int main(){
    int n;cin>>n;
    vector<ll> a(n),b(n);
    for(auto &i:a)cin>>i;
    for(auto &i:b)cin>>i;
    if(accumulate(a.begin(),a.end(),0ll)>accumulate(b.begin(),b.end(),0ll)){cout<<"No";return 0;}
    for(int i=0;i<n;i++)b[i]-=a[i];
    ll aa=0,bb=0;
    
    for(int i=0;i<n;i++){
        if(b[i]>0)aa+=(b[i])/2;
        else if(b[i]<0)bb+=-b[i];
    }
    if(aa>=bb)cout<<"Yes";
    else cout<<"No";
    
}