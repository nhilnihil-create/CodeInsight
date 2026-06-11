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
    int a,b;
    cin >> a >> b;
    if(a>=13){
        cout << b;
    }
    else if(a<=5){
        cout << 0;
    }
    else{
        cout << b/2;
    }

    return 0;
}