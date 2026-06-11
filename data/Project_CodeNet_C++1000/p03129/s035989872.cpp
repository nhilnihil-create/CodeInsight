#include <bits/stdc++.h>
#include <chrono>
#define watch(x) cout << (#x) << " is " << (x) << endl
#define eps 1e-9

typedef long long ll;

using namespace std;

const int N = 1e5;
int a[N+5];

int main()

{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int n, k;

    cin >> n >> k;

    if (k > (n+1)/2) cout << "NO";
    else cout << "YES";

    return 0;
}
