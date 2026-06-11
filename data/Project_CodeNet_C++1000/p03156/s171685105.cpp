#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <string>
#include <cmath>
#include <queue>
#include <tuple>
#include <set>
#include <assert.h>
#include <sstream>
#include <string>
//#include <bits/stdc++.h>
#define maxs(x,y) x = max(x,y)
#define mins(x,y) x = min(x,y)
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define repr(i, n) for (int i = (n) - 1; i >= 0; i--)
#define FOR(i,i0,n) for(int (i)=(i0);(i)<(n);(i)++)
#define FORR(i,i0,n) for(int (i)=(n)-1; (i)>=(i0);(i)--)
#define SORT(x) sort(x.begin(),x.end())
#define SORTR(x) sort(x.begin(),x.end(),greater <>())
#define rn return
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
using namespace std;
using ll = long long;
typedef std::pair<int,int> P;
 #include <boost/multiprecision/cpp_int.hpp>

using bint = boost::multiprecision::cpp_int;
 
 
 
 
int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector<int> p(n);
    rep(i,n) cin >> p[i];
    int s1 = 0;int s2 = 0; int s3 = 0;
    rep(i,n){
        if (p[i] <= a) s1++;
        else if (p[i] > b) s2++;
        else s3 ++;
    }
    cout << min(min(s3,s2),s1);
}