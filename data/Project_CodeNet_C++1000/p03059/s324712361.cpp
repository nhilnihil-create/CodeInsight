#include <iostream>
#include <bitset>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;
using ll = long long int;
const ll MOD = 1e9 + 7;

vector<string> dfs(string s, ll depth, vector<char> symbol)
{
    vector<string> ret;
    if (depth == 0)
    {
        ret.push_back(s);
        return ret;
    }

    for (ll i = 0; i < symbol.size(); i++)
    {
        auto vec = dfs(s + symbol[i], depth - 1, symbol);
        for (auto &&e : vec)
        {
            ret.push_back(e);
        }
    }
    return ret;
}

int main()
{
  ll A, B, T;
  cin >> A >> B >> T;
  cout << (T / A * B) << endl;
}