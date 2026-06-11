#include<cmath>
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
#include<map>
#include<set>
#include<queue>
#include<functional>
#define INF 1e16
#define N (1000000000+7)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<ll,P> Q;


ll gcd(ll a, ll b) {
    if(b==0) return abs(a);
	else return gcd(b, a%b);
}

int main(void){
    int n;
    cin>>n;
    ll ans = 0;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        while(x%2==0)ans++,x/=2;
    }
    cout<<ans<<endl;
    return 0;
}