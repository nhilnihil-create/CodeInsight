#include <bits/stdc++.h>

using namespace std;


void solve(){
    int n, m, x, y, big = -1e9, small = 1e9 + 2;
    cin >> n >> m >> x >> y;
    bool war = false;
    for(int i = 0; i < n; ++i){
        int element;
        cin >> element;
        big = max(big, element);
    }
    int z = big + 1;
    for(int i = 0; i < m; ++i){
        int elemnt;
        cin >> elemnt;
        small = min(small, elemnt);

    }
    if(x < z && z <= y){
        if(z <= small){
            cout << "No War" << endl;
            return;
        }
    }
    cout << "War" << endl;
}

int main()
{
    solve();
    return 0;
}
