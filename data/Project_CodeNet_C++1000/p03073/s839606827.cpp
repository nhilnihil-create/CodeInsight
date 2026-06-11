#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int a = 0;
    int b=0;
    for (size_t i = 0; i < s.length(); i++)
    {
        if((s[i]=='0'&&i%2==0) ||(s[i]=='1'&&i%2==1)){
            a++;
        }
        else{
            b++;
        }
    }
    cout << min(s.length() - a, s.length() - b) << endl;

    return 0;
}