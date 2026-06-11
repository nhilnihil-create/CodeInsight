#include <bits/stdc++.h>
using namespace std;

int64_t MOD = 1000000007;
int64_t MAX = 9223372036854775807;
double PI = 3.141592653589793;

int main()
{
    map<char, char> list;
    list['A'] = 'T', list['T'] = 'A', list['C'] = 'G', list['G'] = 'C';
    char x;
    cin >> x;
    cout << list[x];
}