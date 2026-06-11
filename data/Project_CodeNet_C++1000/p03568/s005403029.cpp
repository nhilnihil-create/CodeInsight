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
    vector<int>S,False(1,-1);
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}

template<typename A,size_t N,typename T>
void Fill(A(&array)[N],const T &val){
    fill((T*)array,(T*)(array+N),val);
}


int main(){
    int n;
    cin >> n;
    int cnt = 1;

    rep(i, n){
        int a;
        cin >> a;
        if(a % 2 == 0)cnt *= 2;
    }

    cout << pow(3, n) - cnt << endl;
}