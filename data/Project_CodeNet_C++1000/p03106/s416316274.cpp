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
    int a,b,k;
    cin >> a >>b >>k;
    int cnt=0;
    for(int i=max(a,b);i>0;i--){
        if(a%i==0&&b%i==0){
            cnt++;
        }
        if(cnt==k){
            cout << i;
            return 0;
        }
    }

    return 0;
}