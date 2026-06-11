#include <iostream>
#include <cmath>
#include <cstdio>
#include <stack>
#include <queue>
#include <bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
    ll n,h,w;
    cin>>n>>h>>w;
    ll small=min(h,w);
    cout<<(n-h+1)*(n-w+1)<<endl;
}