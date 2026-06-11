#include <bits/stdc++.h>
using namespace std;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

#define rep(i,cc,n) for(int i=cc;i<n;++i)
#define lrep(i,cc,n) for(long long i=cc;i<n;++i)
#define sqrep(i,cc,n) for(long long i=cc;i*i<=n;++i)
#define rrep(i,cc,n) for(long i=cc;i>n;--i)
#define pii pair<int, int>
#define pll pair<long long, long long>
 
using ll = long long;

const vector<int> dx = {1, 0, -1, 0};
const vector<int> dy = {0, 1, 0, -1};
const double PI = 3.1415926535;
const ll inf = 1001001001;
const ll e9  = 1000000000;
const ll mod = 1000000007;

int main(){
    int h, w;
    cin >> h >> w;
    vector<vector<int>>board(h+1, vector<int>(w));
    rep(i, 0, h)rep(j, 0, w)cin >> board[i][j];
    int cnt=0;
    vector<pair<pii,pii>>ans;
    rep(i, 0, h){
        if(i%2==0){
            for(int j=0; j<w; j++){
                if(board[i][j]%2==1){
                    if(j==w-1){
                        board[i+1][j]++;
                        if(i==h-1)continue;
                        ans.push_back(pair<pii,pii>(pii(i,j),pii(i+1,j)));
                        cnt++;
                    }
                    else{
                        board[i][j+1]++;
                        ans.push_back(pair<pii,pii>(pii(i,j),pii(i,j+1)));
                        cnt++;
                    }
                    cnt++;
                }
            }
        }else{
            for(int j=w-1; j>=0; j--){
                if(board[i][j]%2==1){
                    if(j==0){
                        board[i+1][j]++;
                        if(i==h-1)continue;
                        ans.push_back(pair<pii,pii>(pii(i,j),pii(i+1,j)));
                        cnt++;
                    }
                    else{
                        board[i][j-1]++;
                        ans.push_back(pair<pii,pii>(pii(i,j),pii(i,j-1)));
                        cnt++;
                    }
                }
            }
        }
    }
    //cout << cnt << endl;
    cout << ans.size() << endl;
    for(auto i:ans){
        cout << i.first.first+1 << " " << i.first.second+1 <<
          " " << i.second.first+1 << " " << i.second.second+1 << endl;
    }
}