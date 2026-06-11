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
    int n;cin>>n;
    VEC(int,a,n);
    int now = a[0];
    int cnt = 1;
    int res = 0;
    rep(i,n){
        if(i==0)continue;
        if(now==a[i]){
            cnt++;
        }
        else {
            res += cnt/2;
            cnt = 1;
            now = a[i];
        }
    }
    res += cnt/2;
    cout<<res<<endl;
}

