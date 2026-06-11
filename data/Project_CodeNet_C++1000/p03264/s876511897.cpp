#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 100005

int k;
string s;

int main()
{
    _FastIO;

    cin >> k;
    int a = k / 2;
    int b = a + k % 2;
    cout << a * b << endl;

    return 0;
}
