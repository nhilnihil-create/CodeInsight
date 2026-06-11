#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

int a[4];
char s[4];

int main()
{
    scanf("%s", s);
    for(int i = 0; i < 3; ++i)
    {
        a[s[i] - 'a']++;
    }
    if(a[0] && a[1] && a[2])
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
