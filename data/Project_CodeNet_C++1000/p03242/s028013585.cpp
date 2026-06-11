#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>
using namespace std;

int main()
{
    string n;
    while(cin >> n)
    {
        string ans = "";
        for(int i = 0; i < n.size(); i++)
        {
            if(n[i] == '1')
                ans += '9';
            else if(n[i] == '9')
                ans += '1';
            else
                ans += n[i];
        }
        cout << ans << endl;
    }
    return 0;
}
