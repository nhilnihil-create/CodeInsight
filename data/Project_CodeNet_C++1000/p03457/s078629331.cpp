#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

void solve()
{
    int N; cin >> N;
    int t=0, x=0, y=0;
    int nt,nx,ny;
    for (int i = 0; i < N; i++){
        cin >> nt >> nx >> ny;
        if (abs(nx-x) + abs(ny-y) > nt-t){
            cout << "No" << endl;
            return;
        }
        if ((abs(nx-x) + abs(ny-y)) % 2 != (nt-t) % 2){
            cout << "No" << endl;
            return;
        }
        t=nt, x=nx, y=ny;
    }
    cout << "Yes" << endl;
    return;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // input();
    solve();
    return 0;
}