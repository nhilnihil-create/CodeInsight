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
    #define chmin(a, b) a = min(a, b)
    #define chmax(a, b) a = max(a, b)
     
    using namespace std;
    using ll = long long;
    using Graph = vector<vector<int>>;
    using P = pair<ll, ll>;
    using T = ll;
     
const int MOD = 1e9 + 7;
const ll ZER = 0;


int main(){
    ll n;
    cin >> n;
    ll res = 0;
    vector<string> s(n);
    rep(i, n)cin >> s[i];
    rep(a, n){
        vector<vector<char>> t(n, vector<char>(n));
        rep(i, n){
            rep(j, n){
                t[(i + a) % n][j] = s[i][j];
            }
        }
        bool f = true;
        rep(i, n){
            rep(j, n){
                if(t[i][j] != t[j][i])f = false;
            }
        }
        if(f)res++;
    }
    cout << res * n << endl;
}

