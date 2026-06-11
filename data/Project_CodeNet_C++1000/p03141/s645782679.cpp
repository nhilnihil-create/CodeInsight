//おまじない
//#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
#include<iomanip>
#include <map>
#include <set>
#include <algorithm>
#include <vector>
#include <string>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define all(a) a.begin(),a.end()
#define P pair<int,int>
#define space ' '
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

const int maxn = 100000;

int main(){
    
    ll n;
    ll sum=0;
    ll f[maxn];
    
    cin >> n;
    rep(i,n){
        ll a,b;cin >> a>>b;
        sum-=b;
        f[i]=a+b;
    }
    
    sort(f,f+n);
    reverse(f,f+n);
    
    rep(i,n){
        sum+=f[i];
        i++;
    }
    
    cout << sum<<endl;
    
    return 0;
}
