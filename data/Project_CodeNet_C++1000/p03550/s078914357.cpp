#include<bits/stdc++.h>

using namespace std;
using ll = long long;

/*
Xが1~Nあるいは1~N-1以外のカードを初手でめくったとして、もしYが「このままだと勝たれる」となったとしても、YはN-1までめくることでabs(A_N-1 - A_N)に押さえ込めるからスコアの最大値は
max(abs(w - A[N]), abs(A[N] - A[N-1]))となる。
*/

int main()
{
    int n, z, w; cin >> n >> z >> w;
    vector<int> a(n);
    for(int i = 0; i < n; i++)cin >> a[i];
    if(n == 1) {
        cout << abs(w - a.back()) << endl;
    } else {
        cout << max(abs(w - a.back()), abs(a.back() - *(a.end() - 2))) << endl;
    }

}