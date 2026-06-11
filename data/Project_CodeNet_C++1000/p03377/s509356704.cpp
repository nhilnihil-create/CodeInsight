#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;

int main(){
    ll A,B,X;
    cin>>A>>B>>X;
    if((A+B)>=X&&A<=X)cout<<"YES";
    else cout<<"NO";
    return 0;
}