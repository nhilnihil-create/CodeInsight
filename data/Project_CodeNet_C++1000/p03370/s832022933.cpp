#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;

int main(){
    int n,x;
    cin >> n >> x;
    int nmin = 1000;
    for(int i = 0; i < n; i++){
        int m; cin >> m;
        x -= m;
        nmin = min(nmin, m);
    }
    cout << n + x/nmin << endl;
    return 0;
}