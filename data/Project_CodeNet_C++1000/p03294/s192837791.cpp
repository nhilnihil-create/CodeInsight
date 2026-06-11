#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

typedef long long ll;
typedef vector<int> vi;


int N; 
void input()
{
    cin >> N;
}

void solve()
{
    int sum = 0;
    for (int i = 0; i < N; ++i){
        int a; cin >> a;
        sum += a;
    }
    cout << sum - N << endl;
}

int main()
{
    cin.tie();
    ios::sync_with_stdio(false);
    input();
    solve();
    return 0;
}