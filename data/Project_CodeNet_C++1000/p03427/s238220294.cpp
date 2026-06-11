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
    vector<int>S,False(1,-1);
    rep(i,n)if(bit&(1<<i))S.push_back(i);
    return S;
}

template<typename A,size_t N,typename T>
void Fill(A(&array)[N],const T &val){
    fill((T*)array,(T*)(array+N),val);
}

ll gcd(ll a,ll b){
    if(a%b==0)return b;
    else return gcd(b,a%b);
}


int solve( int x ){
    if( x == 0 )return 1;
    if( x < 0 )return 0;

    rep(i,6){
        return solve( x - 100 - i );
    }
}

int dp[ 100000 ];
int main(){
    string s;
    cin >> s;

    int res = 0;
    const int len = s.size();

    int sum = 0;
    rep(i, len){
        if( s[i] == '0' )continue;
        sum += s[i] - '0';
        res = max( res , sum - 1 + 9 * ( len - i - 1 ) );
    }
  res = max( res , sum );
    cout << res << endl;
}