#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <iomanip>
#include <map>
#include <bitset>
#include <cstdio>
#include <set>
#include <stack>
#include <queue>
#include <cassert>
#include <numeric>
//#include <bits/stdc++.h>
#define rep(i,n) Rep(i,0,n)
#define Rep(i,k,n) for(int i=k ; i<n ; i++)
#define rep1(i,n) for(int i=1 ; i<=n ; i++)
#define vi vector<int>
#define vii vector<vector<int>>
#define mii map<int,int>
#define Sort(v) sort(v.begin(),v.end())
#define Reverse(v) reverse(v.begin(),v.end())
#define ALL(a)  (a).begin(),(a).end()
#define pb push_back
//#define int ll
typedef long long ll;

const int md = 1000000007;
const int INF = 1<<30;
using namespace std;

string yn(bool x){
    return x ? "Yes" : "No";
}

 

ll judge(ll x,ll y){
    ll cnt = 0;
    while(x%y == 0){
        cnt++;
        x /= y;
    }
    
    return cnt;
}

int main(){
    ll n,p;
    cin >> n >> p;

    ll ans = 1;
    for(ll i = 2 ; i*i <= p ; i++){
        ll check = judge(p,i);
        if(check >= n){
            ans = i;
        }
    }
    
    cout << (n == 1 ? p : ans) << endl;
}
