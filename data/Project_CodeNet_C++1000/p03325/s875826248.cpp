#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const double PI=acos(-1.0);

int N; vector<int> a;
void input()
{
    cin >> N;
    a.resize(N);
    for(int i=0; i<N; ++i) cin >> a[i];
}

void solve()
{
    ll ans = 0;
    for(int i=0; i<N; ++i){
        while(a[i]%2 == 0){
            a[i] /= 2;
            ++ans;
        }
    }
    cout << ans << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}