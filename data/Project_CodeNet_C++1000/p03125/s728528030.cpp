#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000

int main(){
    ll A,B;
    cin>>A>>B;
    if(B%A==0)cout<<(A+B)<<endl;
    if(B%A!=0)cout<<(B-A)<<endl;
}