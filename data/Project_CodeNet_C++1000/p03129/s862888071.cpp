#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    int n, k; cin >> n >> k;
    cout << ((n%2==0?n/2:n/2+1)>=k?"YES":"NO") << '\n';

}

