#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#include <numeric>
#include <cmath>
#include <iomanip> //cout << fixed << setprecision(15) << << endl;
#include <cassert>
#include <limits>
//#include "atcoder/all"

using namespace std;
//using namespace atcoder;

#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
//#define P pair<int,int>

int mx8[] = {0,0,1,-1,-1,1,-1,1};
int my8[] = {-1,1,0,0,-1,-1,1,1};
int mx4[] = {1,-1,0,0};
int my4[] = {0,0,-1,1};


int main(){
    string s,t; cin >> s >> t;
    int sz = s.size(),tz = t.size();

    if(sz < tz){cout << "UNRESTORABLE" << endl; return 0;}
    int i;
    bool ok = false;
    for(i = sz-1; i >= 0; --i){
        int k = tz-1;
        while(k >= 0){
            int a = i-(tz-1-k);
            if(a<0) break;
            if(s[a] == '?' || s[a] == t[k]) {
                k--;
                if(k==-1) {ok = true; break;}
            }else break;
        }
        if(ok) {
            rep(j,i-tz+1){
                if(s[j] == '?') s[j] = 'a';
            }
            for(int j = i+1; j < sz; j++) if(s[j] == '?') s[j] = 'a';
            break;
        }
    }
    if(ok) {
        rep(j, i-tz+1) cout << s[j];
        cout << t;
        for(int j = i+1; j < sz; ++j) cout << s[j];
    }else cout << "UNRESTORABLE" << endl;
}

