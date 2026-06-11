#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;
    vector<int> v[200002];
    for(int i = 0; i < n; i++){
        int x, y;
        cin >> x >> y;
        x--; y--;
        v[x].push_back(y);
    }
    for(int i = 0; i < n; i++) sort(v[i].begin(), v[i].end());
    int l = 1;
    for(int i = 1; i < h; i++){
        int p = lower_bound(v[i].begin(), v[i].end(), l) - v[i].begin();
        if(p){
            cout << i << endl;
            return 0;
        }
        if((int)v[i].size() != p)
            if(v[i][p] == l) continue;
        if(l < w) l++;
    }
    cout << h << endl;
}