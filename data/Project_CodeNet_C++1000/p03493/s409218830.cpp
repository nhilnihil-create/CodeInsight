#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vec;
    int i;
    cin >> i;
    int ans;
    ans += i % 10;
    i /= 10;
    ans += i % 10;
    i /= 10;
    ans += i % 10;
    cout << ans << endl;
}