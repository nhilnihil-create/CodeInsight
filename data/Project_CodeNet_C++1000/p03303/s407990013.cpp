#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
using namespace std;
int main()
{
    string s;
    cin >> s;
    
    int w;
    cin >> w;

    for (int i = 0; i < s.length(); i+=w)
    {
        putchar(s[i]);
    }

    putchar('\n');
    return 0;
}