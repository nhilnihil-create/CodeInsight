#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;

int main(){
    ll a,b,c,d;
    cin>>a>>b>>c>>d;
    ll l=a+b;
    ll r=c+d;
    if(l>r)cout<<"Left";
    else if(l<r)cout<<"Right";
    else cout<<"Balanced";
    return 0;
}