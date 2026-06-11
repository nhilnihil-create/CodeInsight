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

using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
using P = pair<int,int>;

vector<int>bitSearch(int bit,int n){
    vector<int>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}


int dy[2] = {1,0};
int dx[2] = {0,1};
int h,w;
vector<string>s(10);

int main(){
    string s;cin>>s;
    if(s.size() != 26){
        vector<int>C(26, 0);
        for(char c : s){
            C[c - 'a']++;
        }
        char cc;
        rep(i, C.size()){
            if(C[i] == 0){
                cout << s + char('a' + i) << endl;
                return 0;
            }
        }
        cout << s + 'z' << endl;
    }
    else {
        string t = s;
        if(next_permutation( ALL(s) )){
            rep(i, s.size()){
                if(s[i] == t[i])cout << t[i];
                else{
                    cout << s[i] << endl;
                    return 0;
                }
            }
        }
        else cout << -1 << endl;
    }
}

