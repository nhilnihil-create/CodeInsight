#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;

const int N = 200010;
const double eps = 1e-6;

int k;
string s;
vector<string> str;

int main()
{
    cin >> s >> k;

    int len = min((int)s.size(), 5);
    for(int l = 1; l <= len; l++)
        for(int i = 0; i < s.size() - l + 1; i++)
        {
            string t = s.substr(i, l);
            str.push_back(t);
        }

    sort(str.begin(), str.end());
    str.erase(unique(str.begin(), str.end()), str.end());

    cout << str[k - 1] << endl;
    return 0;
}
