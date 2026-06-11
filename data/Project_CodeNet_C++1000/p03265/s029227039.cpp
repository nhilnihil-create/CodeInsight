#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


int main() {
    int x,y,x2,y2;
    cin >> x >> y >> x2 >> y2;
    int dx = x2-x;
    int dy = y2-y;
    int x3 = x2-dy;
    int y3 = y2 + dx;
    int x4 = x - dy;
    int y4 = y + dx;
    cout << x3 << " " << y3 << " " << x4 << " " << y4 << endl;
}
