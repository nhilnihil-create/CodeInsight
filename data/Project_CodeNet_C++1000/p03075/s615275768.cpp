#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
int main(){
    ll k;
    VL a(5);
    cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>k;
    sort(a.begin(),a.end());
    if((a[4]-a[0])>k)cout<<":(";
    else cout<<"Yay!";
}