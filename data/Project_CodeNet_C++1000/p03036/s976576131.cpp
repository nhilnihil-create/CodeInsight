#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
static const double pi=3.141592653589793238462643383279;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int r,d,x;
    cin >> r >> d >> x;
    for(int i=0;i<10;i++){
        int ans=r*x-d;
        cout << ans << endl;
        x=ans;
    }
}