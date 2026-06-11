#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <ctime>
using namespace std;

void solve()
{
    int N,K; cin >> N >> K;
    map<int,int> M;
    for (int i = 0; i < N; ++i){
        int a; cin >> a;
        M[a]++;
    }

    vector<int> Mvalue;
    for(auto m: M) Mvalue.emplace_back(m.second);
    sort(Mvalue.begin(),Mvalue.end());

    int ans = M.size() - K;
    if (ans <= 0) cout << 0 << endl;
    else {
        int sum = 0;
        for (int i = 0; i < ans; ++i) sum += Mvalue[i];
        cout << sum << endl;
    }
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    // int ti = clock();
    // input();
    solve();
    // printf("Execution Time: %.4lf sec\n", 1.0 * (clock() - ti) / CLOCKS_PER_SEC);
    return 0;
}