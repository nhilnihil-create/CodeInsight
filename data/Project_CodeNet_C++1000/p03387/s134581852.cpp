#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int a,b,c;
    cin >> a >> b >> c;
    int m = max(max(a,b),c);
    if(3*m%2==(a+b+c)%2) cout << (3*m-(a+b+c))/2 << endl;
    else cout << (3*(m+1)-(a+b+c))/2 << endl;
}