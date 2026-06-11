#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0;}


char s[55][55];
int main() {
    int h,w;
    cin >> h >> w;
    for(int i = 1;i<=h;i++) {
        for(int j = 1; j<=w;j++) {
            cin >> s[i][j];
        }
    }
    int cnt = 0;
    for(int i = 1;i<=h;i++) {
        for(int j = 1;j<=w;j++) {
            if(s[i][j] == '#' && s[i-1][j] != '#' && s[i+1][j] != '#' && s[i][j-1] != '#' && s[i][j+1] != '#') cnt++;
        }
    } 
    if(cnt==0) cout<<"Yes" << endl;
    else cout << "No" << endl;
}