#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;

int main(){
    VL a(3);
    ll d;
    cin>>a[0]>>a[1]>>a[2]>>d;
    if(abs(a[2]-a[0])<=d)cout<<"Yes";
    else if(a[0]<=a[1]&&a[1]<=a[2]&&(a[2]-a[1])<=d&&(a[1]-a[0])<=d)cout<<"Yes";
    else if(a[0]>=a[1]&&a[1]>=a[2]&&(a[1]-a[2])<=d&&(a[0]-a[1])<=d)cout<<"Yes";
    else cout<<"No";
    return 0;
}