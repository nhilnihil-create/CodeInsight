#include <bits/stdc++.h>
#define S second
#define F first
#define ll long long
#define ld long double

using namespace std;

const ll N = 1e6 + 5, mod = 1e9 + 7;

map<pair<int, pair<int, int> >, int> mop;

char s[N];
int sum[3];

int main()
{
    scanf("%s", s);
    string a = string(s);
    scanf("%s", s);
    string b = string(s);
    reverse(a.begin(), a.end());
    puts(a == b ? "YES" : "NO");
    return 0;
}
