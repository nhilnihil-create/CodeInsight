#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define all(x) (x).begin(),(x).end()
#define cyes cout<<"YES"<<endl
#define cno cout<<"NO"<<endl
#define sp <<" "<<
#define cst(x) cout<<fixed<<setprecision(x)
#define pi 3.14159265359
#define mod 1000000007
using namespace std;
using ll = long long;
using ld = long double;
using Graphi = vector<vector<int>>;
using Graphs = vector<vector<char>>;
using que_a = priority_queue<int, vector<int>, greater<int> >;
using que_d = priority_queue<int>;
using pint = pair<int,int>;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }


int main(){

    int h,w; cin >> h >> w;
    Graphs G(h,vector<char>(w));
    queue<pint> que;
    Graphi dist(h,vector<int>(w,-1));
    vector<int> dx = {-1,0,0,1};
    vector<int> dy = {0,1,-1,0};
    rep(i,h)rep(j,w){
        char c; cin >> c;
        G.at(i).at(j) = c;
        if(c == '#'){
            que.push(make_pair(i,j));
            dist.at(i).at(j) = 0;
        } 
    }
    int count = 0;
    while (!que.empty()) {
        count++;
        pint v = que.front(); // キューから先頭頂点を取り出す
        que.pop();
        int x = v.first;
        int y = v.second;

        // v から辿れる頂点をすべて調べる
        for (int i = 0; i <= 3; i++) {
            int nx = x + dx.at(i);
            int ny = y + dy.at(i);
            if(nx >= 0 && nx <= h-1 && ny >= 0 && ny <= w-1){
                if (dist.at(nx).at(ny) != -1) continue; // すでに発見済みの頂点は探索しない

                // 新たな白色頂点 nv について距離情報を更新してキューに追加する
                dist.at(nx).at(ny) = dist.at(x).at(y) +1;
                que.push(make_pair(nx,ny));
            }
        }
    }
    int ans = -1;

    rep(i,h)rep(j,w) chmax(ans,dist.at(i).at(j));
    cout << ans << endl;

    return 0;   

}
