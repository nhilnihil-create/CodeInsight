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
    int a,b,c;
    cin >> a >> b >> c;
    if (a==b){
        cout << c;
        return 0;
    }
    else if (a==c){
        cout <<b;
        return 0;
    }
    else if (b==c){
        cout << a;
        return 0;
    }

    return 0;
}