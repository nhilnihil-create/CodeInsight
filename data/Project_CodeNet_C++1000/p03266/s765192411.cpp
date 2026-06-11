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

int gcd(int a,int b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}

int main(){
    int n,k;cin>>n>>k;
    ll res;
    if(k%2==1){
        res = pow(n/k,3);
        cout<<res<<endl;
    }
    else {
        int l = k/2;
        ll cnt1 = 0;
        while(l<=n){
            cnt1++;
            l += k;
        }
        ll cnt2 = n/k;
        res = pow(cnt1,3)+pow(cnt2,3);
        cout<<res<<endl;
    }
}

