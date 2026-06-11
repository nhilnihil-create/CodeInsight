#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#include <bitset>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#define inf 1e9+7
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n,k;
    cin >> n >> k;
    double ans=0;
    for(int i=1;i<=n;i++){
        int num=0;
        while(i*pow(2,num)<k) num++;
        ans+=(1.0/n)*(pow(0.5,num));
    }
    printf("%.12f\n",ans);
}