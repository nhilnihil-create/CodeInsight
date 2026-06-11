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
using P = pair<ll, ll>;

const int Z = 30000;
bool dpx[Z];
bool dpy[Z];
bool tmp[Z];

int main(){
    dpx[0] = dpy[0] = true;
    string s;
    int x, y;
    cin >> s >> x >> y;
    const int len = s.size();
    int z = 0;
    while(z < len && s[z] != 'T'){
        z++;
    }
    
    x -= z;
    if(s[z] == 'T')z++;
    int cnt = 0;
    s += "T";
    int t = 0;              //0のときx, 1のときy
    for(; z <= len; z++){
        if(s[z] == 'T'){
            t ^= 1;
            fill(tmp, tmp + Z, false);

            rep(i, Z){
                if(t){
                    if(!dpy[i])continue;
                    tmp[i + cnt] = tmp[abs(i - cnt)] = true;
                }
                else {
                    if(!dpx[i])continue;
                    tmp[i + cnt] = tmp[abs(i - cnt)] = true;
                }
            }
            cnt = 0;
            swap(tmp, t ? dpy : dpx);
        }
        else cnt++;
    }
    if(dpx[abs(x)] && dpy[abs(y)])cout << "Yes" << endl;
    else cout << "No" << endl;
}
