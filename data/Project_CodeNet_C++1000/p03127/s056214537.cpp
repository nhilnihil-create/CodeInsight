#include<iostream>
#include<string>
#include<stdio.h>
#include<stdlib.h>
#include <algorithm>
#include <set>
#include<math.h>
#include<cmath>
#include<vector>
#include<map>
#include<random>
using namespace std;
#define ll long long 

ll gcd(ll a,ll b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

int main(){
    int n;cin >> n;
    vector<ll>a(n);
    for(int i = 0;i < n;i++)cin >> a[i];
    ll ans = a[0];
    for(int i = 0;i < n;i++){
        ans = gcd(ans,a[i]);
    }
    cout << ans << endl;


}