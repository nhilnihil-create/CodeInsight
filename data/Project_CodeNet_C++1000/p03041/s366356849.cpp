#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <cstdlib>
#include <cmath>
#include <stack>
#include <map>
#define _GLIBCXX_DEBUG
using namespace std;
using ll = long long;

int main()
{
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    if (s[k-1] == 'A')
    {
        s[k-1] = 'a';
    }
    if (s[k-1] == 'B')
    {
        s[k-1] = 'b';
    }
    if (s[k-1] == 'C')
    {
        s[k-1] = 'c';
    }
    for (int i = 0; i < n; i++)
    {
        cout << s[i];
    }
    cout << endl;
}