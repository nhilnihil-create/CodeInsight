#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;
 
int main(){
    ll N,A,B;
    cin>>N>>A>>B;
    if((N*A)<=B)cout<<(N*A);
    else cout<<B;
    return 0;
}