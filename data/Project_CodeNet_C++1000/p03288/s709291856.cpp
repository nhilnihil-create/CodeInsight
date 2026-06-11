#include <bits/stdc++.h>
using namespace std;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)
#define VL vector<ll>
#define INF 100000000
typedef long long ll;

int main(){
    ll R;
    cin>>R;
    if(R<1200)cout<<"ABC";
    else if(R<2800&&R>=1200)cout<<"ARC";
    else cout<<"AGC";
    
    return 0;
}