#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#include <map>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uld = unsigned long long;
using P = pair<int,int>;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
//struct area

//function area

//main area
int main(){
    ll a, b, c, x;
    cin >> a >> b >> c >> x;
    cout << (a-b)*(x%2==1 ? -1 : 1) << endl;
}
/*

a b c                   a-b                 a-b
b+c a+c a+b             b+c-(a+c)           a-b
2a+b+c a+2b+c a+b+2c    2a+b+c-(a+2b+c)     a-b

*/