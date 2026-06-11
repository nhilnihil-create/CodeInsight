#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <algorithm>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)

int main() {
    int h,w,ans=1,ty;
    cin>>h>>w;
    vector<string>grid(h);
    rep(i,h)cin>>grid[i];
    rep(i,h)rep(j,w)if(grid[i][j]=='#'){
        ty=1;
        if(i>0&&grid[i-1][j]=='#')ty=0;
        else if(i<h-1&&grid[i+1][j]=='#')ty=0;
        else if(j>0&&grid[i][j-1]=='#')ty=0;
        else if(j<w-1&&grid[i][j+1]=='#')ty=0;
        
        if(ty)ans=0;
    }
    if(ans)cout<<"Yes";
    else cout<<"No";
	return 0;
}
