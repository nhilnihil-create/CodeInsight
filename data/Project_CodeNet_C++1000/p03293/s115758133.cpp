#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    for(int i = 0; i < s1.size(); i++)
    {
        if(s1 == s2) return cout << "Yes\n", 0;
        s1.insert(s1.begin(), s1.back());
        s1.pop_back();
    }
    cout << "No\n";
}