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
using P = pair<int,ll>;

vector<int>bitSearch(int bit,int n){
    vector<int>S;
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}

ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}




int main(){
    int n,k;cin>>n>>k;
    string s;cin>>s;
    vector<int>cnt;
    int now = 0;
    if(s[0]=='1'){
        cnt.push_back(0);
        now++;
    }
    rep(i,n){
        int c = 0;
        while(s[i]-'0'==now){
            i++;
            c++;
        }
        i--;
        cnt.push_back(c);
        now = 1-now;
    }
  //for(auto x : cnt)cout<<x<<endl;
    int count = 0;
    int sum = 0;
    int r = 0;
    int res = 0;
    rep(l,cnt.size()){
        //if(l%2==0)count++;
      //cout<<l<<" "<<r<<" "<<count<<endl;
        while(r<cnt.size() && count+(1-r%2)<=k){
            if(r%2==0)count++;
            //if(count>k)break;
            sum += cnt[r];
            r++;
        }
      //cout<<l<<" "<<r<<" "<<count<<" "<<sum<<endl;
        res = max(res,sum);
        if(l==r)r++;
        else sum -= cnt[l];

        if(l%2==0)count--;
    }
    cout<<res<<endl;
}

