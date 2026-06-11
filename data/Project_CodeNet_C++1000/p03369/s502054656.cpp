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
#define input(x) cin >> x
#define print(x) cout << x << endl
#define rep(a,n) for(int i = a; i < n; i++)
#define ll long long int
using namespace std;

int main(){
    string s; int ans = 700;
    input(s);
    rep(0,3){
        if (s[i]=='o') ans += 100;
    }
    print(ans);
    return 0;
}
