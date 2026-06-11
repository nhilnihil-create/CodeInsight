#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

int abs(int x, int y){
    int r = (x>y) ? x-y : y-x;
    return r;
}

int main(void){
    int n;
    cin >> n;
    int pt = 0, px = 0, py = 0;
    bool suc = true;
    for(int i=1; i<=n; i++){
        int t, x, y;
        cin >> t >> x >> y;
        int dr = abs(x, px) + abs(y, py);
        int dt = t - pt;
        if(dt >= dr && dt%2 == dr%2){
            pt = t;
            px = x;
            py = y;
            continue;
        }
        suc = false;
        break;
    }
    if(suc) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}