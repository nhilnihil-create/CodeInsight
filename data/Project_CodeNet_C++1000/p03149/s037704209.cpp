#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0); ios::sync_with_stdio(false);

    int count[10]; memset(count, 0, sizeof count);
    int N;
    for (int i = 0; i < 4; i++) {
        cin >> N;
        count[N]++;
    }
    
    cout << (count[1] == 1 && count[9] == 1 && count[7] == 1 && count[4] == 1 ? "YES" : "NO") << endl;
}
