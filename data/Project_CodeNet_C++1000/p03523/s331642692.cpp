#include<iostream>
#include<stdio.h>
//#include <bits/stdc++.h>
#include<vector>
#include<float.h>
#include<iomanip>
#include<algorithm>
#include<string>
#include<cstring>
#include<math.h>
#include<cmath>
#include<sstream>
#include<set>
#include<map>
#include<queue>
#include <cassert>
#include <cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()
#define chmax(a, b) a = max(a, b)
#define chmin(a, b) a = min(a, b)


using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

int main(){
    string s;
    cin >> s;
    if(s.size() > 9 || s.size() < 5){
        cout << "NO" << endl;
    }
    else {
        string t = "AKIHABARA";
        int now = 0;
        rep(i, t.size()){
            if(t[i] != 'A' && t[i] != s[now]){cout << "NO" << endl;return 0;}
            if(t[i] == s[now])now++;
        }
        if(now == s.size())cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}