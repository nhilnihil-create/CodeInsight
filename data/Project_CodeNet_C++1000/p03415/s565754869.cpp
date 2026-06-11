#include <bits/stdc++.h>
using namespace std;

int64_t mod = 1000000007;
int64_t large = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    vector<string> list(3);
    for (int i = 0; i < 3; i++)
        cin >> list[i];
    cout << list[0][0] << list[1][1] << list[2][2];
}