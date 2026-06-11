#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;
    int x = n * a;
    cout << (x > b ? b : x) << endl;
}