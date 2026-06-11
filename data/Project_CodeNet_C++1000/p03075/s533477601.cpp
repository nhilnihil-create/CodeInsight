#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<tuple>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<deque>
#include<cmath>
#include<stack>
#include<string.h>
#include <iomanip>
#define rep(i,n) for(int i = 0;i<n;i++)
#define _GLIBCXX_DEBUG
using ll = long long; 
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    int a,b,c,d,e,k;
    cin >> a >> b >> c >> d >> e >> k;
    if(b-a>k || c-a>k||d-a>k||e-a>k||c-b>k||d-b>k||e-b>k||d-c>k||e-c>k||e-d>k) cout << ":(" << endl;
    else cout << "Yay!" << endl;
}