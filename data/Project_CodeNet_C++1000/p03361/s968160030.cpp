/////////////////////////////////////////
///       Please Give Me AC!!!!!      ///
/////////////////////////////////////////

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

int main() {
    const int dx[] = {1, -1, 0, 0};
    const int dy[] = {0, 0, 1, -1};

    int H, W;
    cin>> H >> W;

    vector<string> s(H);
    forin(s);

    bool IsOk = true;
    rep(i, H)rep(j, W){
        if(s[i][j] == '#'){
            bool IsNextOk = false;
            rep(k, 4){
                int y = i + dy[k];
                int x = j + dx[k];
                if(x >= 0 && x < W && y >= 0 && y < H){
                    if(s[y][x] == '#') IsNextOk = true;
                }
            }
            if(!IsNextOk) IsOk = false;
        }
    }
    if(IsOk) cout<< "Yes" << endl;
    else cout<< "No" << endl;
}