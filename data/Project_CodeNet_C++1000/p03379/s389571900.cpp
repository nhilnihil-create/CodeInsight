#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int N; vector<int> X,Xsort;
void input()
{
    cin >> N;
    X.resize(N); Xsort.resize(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i];
        Xsort[i] = X[i];
    }
    sort(Xsort.begin(),Xsort.end());
}

void solve()
{
    int cen1 = Xsort[N/2-1], cen2 = Xsort[N/2];
    for (int i = 0; i < N; ++i){
        if (X[i] <= cen1) cout << cen2 << endl;
        else cout << cen1 << endl;
    }
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}