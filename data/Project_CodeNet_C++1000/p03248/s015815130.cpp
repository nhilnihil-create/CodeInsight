#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;
bool f(string s)
{
    int n = s.size();
    if(s[0] == '0' || s[n-1] == '1')
    {
        return 1;
    }
    for(int i = 0; i < n-1; i++)
    {
        if(s[i] != s[n-2-i])
            return 1;
    }
    int x = 0;
    for(int i = 1; i < n; i++)
    {
        printf("%d %d\n", x+1, i+1);
        if(s[i-1] == '1')
            x = i;
    }
    return 0;
}
int main()
{
    string s;
    while(cin >> s)
    {
        if(f(s))
            printf("-1\n");
    }
    return 0;
}
