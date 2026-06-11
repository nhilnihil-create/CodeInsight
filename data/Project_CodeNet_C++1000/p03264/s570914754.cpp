#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int k;
    cin >> k;
    int ans=0;
    for(int i=1;i<=k;i+=2){
        for(int j=2;j<=k;j+=2) ++ans;
    }
    cout << ans << endl;
}