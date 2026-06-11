#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;

int main(){
    VL a(3);
    cin>>a[0]>>a[1]>>a[2];
    sort(a.begin(),a.end());
    //cout<<0+(a[2]-a[1])+(a[1]-a[0]);
    cout<<a[2]-a[0];
    return 0;
}