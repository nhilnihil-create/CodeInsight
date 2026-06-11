#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
int h_dire[8]={-1,0,1,-1,1,-1,0,1};
int w_dire[8]={1,1,1,0,0,-1,-1,-1};
int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> field(h,vector<char>(w));
    rep(i,0,h){
        rep(j,0,w){
            cin >> field[i][j];
        }
    }
    rep(i,0,h){
        rep(j,0,w){
            if(field[i][j]=='.'){
                int bomb = 0;
                rep(k,0,8){
                    int nh = i+h_dire[k];
                    int nw = j+w_dire[k];
                    if(nh>=0&&nh<h&&nw>=0&&nw<w){
                        if(field[nh][nw]=='#'){
                            bomb++;
                        }
                    }
                }
                field[i][j]='0'+bomb;
                //cout<<field[i][j]<<endl;

            }
        }
    }
    rep(i,0,h){
        rep(j,0,w){
            cout<<field[i][j];
        }
        cout<<endl;
    }
  return 0;
}