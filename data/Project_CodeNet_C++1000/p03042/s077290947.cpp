#include <iostream>
#include <algorithm>
#include <cmath>
#include <limits>
#include <iomanip>
#include <vector>
#include <cstring>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uld = unsigned long long;
const ll mod = 1e9+7;
const int dx[4] = {0,1,0,-1};
const int dy[4] = {1,0,-1,0};
template<class T> inline bool chmax(T &a,T& b){if(a < b){a = b; return true;} else return false;}
template<class T> inline bool chmin(T &a,T& b){if(a > b){a = b; return true;} else return false;}
int main(){
    int n;
    cin >> n;
    int UP = n / 100;
    int DOWN = n % 100;
    if(1 <= UP && UP <= 12){
        if(1 <= DOWN && DOWN <= 12) cout << "AMBIGUOUS" << endl;
        else cout << "MMYY" << endl;
    }
    else{
        if(1 <= DOWN && DOWN <= 12) cout << "YYMM" << endl;
        else cout << "NA" << endl;
    }
}