#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <tuple>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <random>
#include <set>
#include <stack>
#include <time.h>

//#include <bits/stdc++.h>
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,i0,n) for(int (i)=(i0);(i)<(n);(i)++)
#define FORR(i,i0,n) for(int (i)=(n)-1; (i)>=(i0);(i)--)
#define SORT(x) sort(x.begin(),x.end())
#define SORTR(x) sort(x.begin(),x.end(),greater<int>())
#define rn return
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple

using namespace std;
using ll = long long;
typedef std::pair<int,int> pii;
typedef std::pair<int,double> pid;
typedef std::vector<int> vi;
typedef std::vector<pii> vii;

#define PI 3.14159265358979323846264338327950L
const int mod = 1000000007;



void solve(){
    int n;
    int ans = 0;
    cin >> n;
    vector<string> s(n);
    rep(i,n) cin >> s[i];
    
    
    int ba = 0, _a = 0, b_ = 0;
    
    for(auto e:s){
        for(int i = 0; i < e.size()-1;i++){
            if (e[i] == 'A' && e[i+1] == 'B') ans++;
        }
        
        if (e[0] == 'B' && e.back() == 'A') ba++;
        else if (e[0] =='B') b_++;
        else if (e.back() == 'A') _a++;
    }
    

    if (ba) ans += ba-1;
    
    if (_a && ba){
        ans++;
        _a--;
    }
    
    if (b_ && ba){
        ans++;
        b_--;
    }
    
    ans += min(b_,_a);
    
    cout << ans;
    
    
}



int main(){
    int T;
    T = 1;
    // cin >> T;
    while(T--){
        solve();
        cout << endl;
    }
}



































