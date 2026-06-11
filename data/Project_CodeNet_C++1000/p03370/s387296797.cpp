#include <bits/stdc++.h>
#include <algorithm>
#include <map>
#include <cstdlib>
#include <cmath>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
const double pi=acos(-1);

ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
    int n,x;
    cin >> n >> x;
    int mi=10000,sum=0;
    for(int i=0;i<n;i++){
        int m;
        cin >> m;
        sum+=m;
        mi=min(mi,m);
    }
    cout << n+(x-sum)/mi << endl;
}
