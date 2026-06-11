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

template<typename A,size_t N,typename T>
void Fill(A(&array)[N],const T &val){
    fill((T*)array,(T*)(array+N),val);
}


int main(){
    int N;cin>>N;
    map<int,int>mp;
    REP(n,1,N){
        int now = n;
        for(int i=2;i*i<=n;i++){
            while(now%i==0){
                mp[i]++;
                now /= i;
            }
        }
        if(now>1)mp[now]++;
    }
    vector<int>v;
    for(auto m : mp)v.push_back(m.second);

    int res = 0;
    int len = v.size();
    rep(i,len)if(v[i]>=74)res++;

    rep(i,len){
        REP(j,i+1,len-1){
            if(v[i]>=2 && v[j]>=24)res++;
            if(v[i]>=24 && v[j]>=2)res++;
            if(v[i]>=4 && v[j]>=14)res++;
            if(v[i]>=14 && v[j]>=4)res++;
        }
    }
    
    rep(i,len){
        REP(j,i+1,len-1){
            REP(k,j+1,len-1){
                if(v[i]>=2 && min(v[j],v[k])>=4)res++;
                if(v[j]>=2 && min(v[i],v[k])>=4)res++;
                if(v[k]>=2 && min(v[j],v[i])>=4)res++;
            }
        }
    }
  cout<<res<<endl;
    //for(auto m : mp)cout<<m.first<<" "<<m.second<<endl;
}