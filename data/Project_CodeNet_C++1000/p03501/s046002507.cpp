#include <bits/stdc++.h>
using namespace std;

int min(int a, int b){return a > b ? b : a;}

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    cout << min(n * a, b) << endl;
}