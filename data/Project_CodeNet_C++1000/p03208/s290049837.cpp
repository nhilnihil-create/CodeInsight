#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1000000010;

int K,N; vector<int> h;
void input()
{
    cin >> N >> K;
    h.resize(N);
    for(int i=0; i<N; ++i) cin >> h[i];
}

void solve()
{
    sort(h.begin(),h.end());
    int MIN = INF;
    for(int i=0; i<=N-K; ++i){
        MIN = min(MIN,h[i+K-1]-h[i]);
    }
    cout << MIN << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}