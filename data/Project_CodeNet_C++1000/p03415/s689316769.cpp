#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define Rep(i,n) for(int i=1;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define Rrep(i,n) for(int i=n-1;i>0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
#define P pair<int,int>
#define Pll pair<ll,ll>
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}

int main(){
    string s[3];
    rep(i,3) cin >> s[i];
    rep(i,3) cout << s[i][i];
}
