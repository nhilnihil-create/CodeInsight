#include <stdio.h>
#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <algorithm>
#include <cmath>
#include <utility>
#include <iomanip>
#define input(a) cin >> a
#define input(a,b) cin >> a >> b
#define input(a,b,c) cin >> a >> b >> c
#define print(x) cout << x << endl
#define rep(a,n) for(int i = a; i < n; i++)
#define ll long long int
using namespace std;


int main(){
    int a,b,c,ans;
    input(a,b,c);
    ans = min(b/a, c);
    print(ans);
    
    return 0;
}
