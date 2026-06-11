#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string ans = "War";
    int n,m,x,y,vx_max = -100,vy_min = 1000;
    cin >> n >> m >> x >> y;

    vector<int>vx(n);
    vector<int>vy(m);

    for(int i = 0;i < n;i++){
        cin >> vx[i];
        vx_max = max(vx_max,vx[i]);
    }

    for(int i = 0;i < m;i++){
        cin >> vy[i];
        vy_min = min(vy_min,vy[i]);
    }

    for(int i = vx_max+1;i < vy_min+1;i++){
        if(x < i && i <= y)ans = "No War";
    }
    
    cout << ans << endl;

    return 0;
}