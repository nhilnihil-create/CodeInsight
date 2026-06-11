#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    if(s == "abc") printf("Yes\n");
    else printf("No\n");
    return 0;
}
