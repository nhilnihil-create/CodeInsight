#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000

int main(){
    ll H,W,h,w;
    cin>>H>>W>>h>>w;
    cout<<(H*W-(h*W+w*H-h*w));
}