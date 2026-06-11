#include<cstdio>
#include<cstring>
#include<cmath>
#include<cassert>
#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
using namespace std;
#define DEBUG(x) cout<<#x<<"="<<x<<endl
#define DEBUG2(x,y) cout<<#x<<"="<<x<<","<<#y<<"="<<y<<endl
typedef long long ll;
class Solver{
public:
    static const int MAXN=50;
    char grid[2*MAXN][2*MAXN+1];
    void output(){
        for(int u=0;u<2*MAXN;u++){
            cout<<grid[u]<<'\n';
        }
    }
    void solve(){
        int w,b;
        cin>>w>>b;
        w--;b--;
        for(int u=0;u<MAXN;u++){
            for(int v=0;v<2*MAXN;v++){
                grid[u][v]='#';
            }
            if(u%2==0&&w){
                for(int v=0;v<2*MAXN&&w;v+=2){
                    grid[u][v]='.';
                    w--;
                }
            }
        }
        for(int u=2*MAXN-1;u>=MAXN;u--){
            for(int v=0;v<2*MAXN;v++){
                grid[u][v]='.';
            }
            if(u%2==1&&b){
                for(int v=0;v<2*MAXN&&b;v+=2){
                    grid[u][v]='#';
                    b--;
                }
            }
        }
        cout<<100<<" "<<100<<'\n';
        output();
    }
};
int main()
{
    // freopen("in.txt","r",stdin);
    (new Solver())->solve();
}