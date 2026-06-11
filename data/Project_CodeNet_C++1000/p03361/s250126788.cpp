#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define SIZE 200005
#define INF 1000000005LL
#define MOD 1000000007
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;
vector<int> x = {1,-1,0,0};
vector<int> y = {0,0,-1,1};
int main(){
    int h,w;
    cin >> h >> w;
    vector<vector<char>> field(h,vector<char>(w));
    rep(i,0,h){
        rep(j,0,w){
            cin >> field[i][j];
        }
    }
    int out = 0;
    rep(i,0,h){
        rep(j,0,w){
            if(field[i][j]=='#'){
                int cnt = 0;
                rep(k,0,4){
                    
                    if(i+x[k]>=0&&i+x[k]<h&&j+y[k]>=0&&j+y[k]<w){
                        if(field[i+x[k]][j+y[k]]=='#'){
                            cnt++;
                        }
                    }
                    
                }
                if(cnt==0){
                        //cout<<i<<j<<endl;
                        out = 1;
                        break;
                }
            }
        }
    }
    if(out){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }

  return 0;
}