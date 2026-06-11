#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
#define FastIO ios::sync_with_stdio(false), cin.tie(NULL);
#define all(x) x.begin(), x.end()
#define pb push_back
#define endl '\n'
typedef long long ll;


int main()
{
   FastIO;
   string s;
   cin >> s;
   if (s.size() == 2) cout << s;
   else reverse(all(s)), cout << s;
   return 0;
}
