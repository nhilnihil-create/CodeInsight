#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;

int main(){
    ll K;
    cin>>K;
    ll gu=K/2;
    ll ki=K-gu;
    cout<<gu*ki;
    return 0;
}