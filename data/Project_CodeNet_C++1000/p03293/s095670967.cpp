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
//typedef long long ll;
//typedef long double ld;
//typedef unsigned long long ull;
//typedef unsigned long double uld;
typedef pair<int,int> P;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
//struct area

//function area

//main area
int main(){
    string s, t;
    cin >> s >> t;
    int n = s.size();
    vector<char> check(2*n);
    rep(i,2*n){
        check[i] = s[i%n];
    }
    bool ans = false;
    rep(i,n){
        bool res = true;
        rep(j,n){
            if(t[j] != check[i+j]) res = false;
        }
        if(res) ans = true;
    }
    cout << (ans ? "Yes" : "No") << endl;
}
/*



*/