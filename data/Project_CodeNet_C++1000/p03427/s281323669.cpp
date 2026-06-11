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
using ll = long long;
const int INF = 1e6;
using namespace std;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
int main(){
    ll n;
    cin >> n;
    string s = to_string(n);
    int size = s.size();
    int ans = (s[0]-'0')-1 + (size-1)*9;
    bool check = true;
    rep1(i,size-1){
        if(s[i]!='9') check = false;
    }
    if(check) ans = (size-1)*9 + (s[0]-'0');
    cout << ans << endl;
}