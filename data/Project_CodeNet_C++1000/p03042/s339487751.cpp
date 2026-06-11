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
    int s;
    cin >> s;
    int a,b;
    a = s/100;
    b = s - a*100;
    bool q,w;
    q = false;
    w = false;
    if(0<a&&a<=12) q = true;
    if(0<b&&b<=12) w = true;
    if(q&&w) cout << "AMBIGUOUS";
    else if(!q&&w) cout << "YYMM";
    else if(q&&!w) cout << "MMYY";
    else cout << "NA";
    return 0;
}