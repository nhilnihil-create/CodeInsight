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
    int a,b;
    cin >> a >> b;
    vector<int> A(1000);
    A[1]=1;
    for(int i=2;i<1000;i++){
        A[i]=A[i-1]+i;
    }
    int diff=abs(a-b);
    int ans=A[diff]-max(a,b);
    cout << ans << endl;
}