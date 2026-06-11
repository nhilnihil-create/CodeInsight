#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N;
    int t,x,y;
    int lt,lx,ly;
    int need;
    bool check = true;
    
    cin >> N;
    lt = lx = ly = 0;
    for(int i=0;i<N;i++) {
        cin >> t >> x >> y;
        need = abs(x-lx) + abs(y-ly);
        if((t-lt) < need) check = false;
        if((t-lt-need)%2) check = false;
        lt = t;
        lx = x;
        ly = y;
    }

    if(check) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
