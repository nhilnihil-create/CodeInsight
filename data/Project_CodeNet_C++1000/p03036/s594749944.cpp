#include<bits/stdc++.h>
using namespace std;

void saiki(int r, int D, int x, int cnt) {
    if (cnt>10) return;
    int nx = r*x-D;
    cout << nx << "\n";
    saiki(r, D, nx, cnt+1);
}

int main() {
    int r, D, x;
    cin >> r >> D >> x;
    saiki(r, D, x, 1);
}