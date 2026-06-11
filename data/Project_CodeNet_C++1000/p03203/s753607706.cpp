#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int h, w, n, x, y, z=1, ans;
    vector<int> v[200001];
    cin >> h >> w >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        v[y].push_back(x);
    }
    ans = h;
    for(int i=1;i<=w;i++){
        sort(v[i].begin(), v[i].end());
    }
    
    for(int i=1;i<=w;i++){
        for(int j=0;j<v[i].size();j++){
            if(v[i][j]>z){
                ans = min(ans, v[i][j]-1);
            }
        }
        if(i==w)break;
        z++;
        for(int j=0;j<v[i+1].size();j++){
            if(v[i+1][j]==z)z++;
        }
    }
    cout << ans << endl;
	return 0;
}