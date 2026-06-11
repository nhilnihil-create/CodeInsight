#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int main(){
    int H,W;
    int N;
    cin >> H >> W >> N;
    vector<int> wall[200002];
    for(int i=0;i<N;i++){
        int x,y;
        cin >> x >> y;
        wall[x].push_back(y);
    }
    wall[H+1].push_back(1);

    int y=1;
    for(int x=1;x<=H;x++){
        sort(wall[x+1].begin(), wall[x+1].end());
        if(wall[x+1].size()>0 && wall[x+1][0]<=y){
            cout << x << endl;
            return 0;
        }
        if(wall[x+1].size()==0 || wall[x+1][0]>y+1) y++;
    }
    return 0;
}