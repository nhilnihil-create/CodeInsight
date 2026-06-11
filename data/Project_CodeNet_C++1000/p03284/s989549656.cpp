#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;
    cout << ((N % K) ? 1 : 0) << endl; 
    return 0;
}