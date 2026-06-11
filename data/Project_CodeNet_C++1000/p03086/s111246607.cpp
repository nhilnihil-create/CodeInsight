//https://atcoder.jp/contests/abc122/tasks/abc122_b

#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<char> arr = {'A', 'C', 'G', 'T'};
    string s;
    cin >> s;
    int a = 0;
    int temp = 0;
    for (int i = 0; i < s.length(); i++)
    {
        temp = count(arr.begin(), arr.end(), s[i]) ? temp + 1 : 0;
        a = max(a, temp);
    }
    cout << a << endl;
}
