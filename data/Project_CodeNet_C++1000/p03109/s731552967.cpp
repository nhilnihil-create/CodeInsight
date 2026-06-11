#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}

int main() {
    int y,m,d;
    char c1,c2;
    cin >> y >> c1 >> m >> c2 >> d;
    if(m<=4) cout << "Heisei" << endl;
    else cout << "TBD" << endl;

}