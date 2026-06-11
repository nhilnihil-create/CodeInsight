#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() );
using namespace std;
using ll = long long;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

bool isIN(int y, int x){
    return 0<=y&&y<100 && 0<=x&&x<100;
}

int main(){
    int a, b;
    cin >> a >> b;

    int m[100][100];
    rep(i, 100){
        rep(j, 100) m[i][j] = (i < 50);
    }

    int cnt = 0;
    for(int i=0; i<50; i+=2){
        for(int j=0; j<100; j+=2){
            if(a == 1) i=50, j=100;
            m[i][j] = 0;
            cnt++;
            if(cnt == a-1) i=50, j=100;
        }
    }

    cnt = 0;
    for(int i=99; i>50; i-=2){
        for(int j=0; j<100; j+=2){
            if(b == 1) i=0, j=100;
            m[i][j] = 1;
            cnt++;
            if(cnt == b-1) i=0, j=100;
        }
    }

    cout << 100 << " " << 100 << endl;
    rep(i, 100){
        rep(j, 100) cout << (m[i][j] ? "#" : ".");
        cout << endl;
    }
}