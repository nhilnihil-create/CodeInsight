#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define drep(i,n) for(int i = (n)-1; i >= 0; --i)
#define all(x) (x).begin(),(x).end()
#define SZ(x) ((int)(x).size())
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<bool> vb;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
int const INF = 1 << 30;


int main()
{
    int w,b;
    cin >> w >> b;
    w--; b--;

    //Background: L -> '#', R -> ' .'
    vector<vector<char>> L(100,vector<char>(50,'#'));
    vector<vector<char>> R(100,vector<char>(50,'.'));

    rep(i,50) {
        rep(j,10) {
            if(10*i + j < w) L[i*2][j*2] = '.';
            if(10*i + j < b) R[i*2][49-j*2] = '#';
        }
    }

    cout << 100 << ' ' << 100 << endl;
    rep(i,100) {
        rep(j,100) {
            if(j < 50) cout << L[i][j];
            else cout << R[i][j-50];
        }
        cout << endl;
    }
    return 0;
}