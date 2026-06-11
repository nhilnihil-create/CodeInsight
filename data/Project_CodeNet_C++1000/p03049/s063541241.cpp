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
#include<cassert>
#include<cmath>
#include<cstdint>

#define INF 1e9
#define rep(i,n)for(int i=0;(i)<(int)(n);i++)
#define REP(i,a,b)for(int i=(int)(a);(i)<=(int)(b);i++)
#define VEC(type, c, n) std::vector<type> c(n);for(auto& i:c)std::cin>>i;
#define vec(type,n) vector<type>(n)
#define vvec(m,n) vector<vector<int>> (int(m),vector<int>(n))
#define ALL(a)  (a).begin(),(a).end()

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<ll, ll>;

const ll MOD = INF + 7;



int main(){
    int n;
    cin >> n;
    VEC(string, s, n);
    int head = 0, back = 0, same = 0;
    int res = 0;
    rep(i, n){
        if(s[i][0] == 'B' && s[i][s[i].size() - 1] == 'A')same++;
        rep(j, s[i].size()){
            if(j == 0){
                if(s[i][j] == 'B')head++;
            }
            if(j == s[i].size() - 1){
                if(s[i][j] == 'A')back++;
                break;
            }
            
            if(s[i][j] == 'A' && s[i][j + 1] == 'B')res++;
        }
    }
    res += min(head, back);
    if(head == back && back == same && same != 0)res--;
    cout << res << endl;
}