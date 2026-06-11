#include<bits/stdc++.h>
#define PI acos(-1.0)
#define pb push_back
#define F first
#define S second
using namespace std;
typedef long long ll;
const int N=2e5+5;
const int MOD=1e9+7;
//ll a[N],sum[N];

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    
    ll a,b;
    cin >>a>>b;
    if(a+b==15) cout <<"+"<<endl;
    else    if(a*b==15) cout <<"*"<<endl;
    else    cout <<"x"<<endl;

    return 0;
}
