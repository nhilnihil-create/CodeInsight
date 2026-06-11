#include <cstdio>
#include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <cmath>
#include <functional>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#define rep(i,n) for (int i=0;i<n;i++)
using ll = long long;
using namespace std;

void solve(){

}
int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int d,k;
    cin >> d >> k;
    if(k==100){
        k+=1;
        rep(i,d){
            k*=100;
        }
    }
    else{
        rep(i,d){
            k*=100;
        }
    }
    cout << k;

    return 0;
}