#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <set>
using namespace std;

int main(){
    int H, W, N;
    cin >> W >> H >> N;
    vector<set<int>> st(H);
    for(int i=0; i<N; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        st[y].insert(x);
    }
    for(int i=0; i<H; i++)
        st[i].insert(W);

    int ans = W;
    int x = 0;
    for(int y=0; y<H; y++){
        for(auto itr=st[y].begin(); itr!=st[y].end(); itr++){
            int xx = (*itr);
            if(xx <= x) continue;
            else{
                ans = min(ans, xx);
                break;
            }
        }
        if(y == H-1) break;
        x++;
        while(st[y+1].find(x)!=st[y+1].end()) x++;
    }
    cout << ans << endl;
    return 0;
}