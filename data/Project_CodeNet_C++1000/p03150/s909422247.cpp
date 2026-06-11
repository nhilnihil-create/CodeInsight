#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod107 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1)

const ll INF = 10010001010;
const int inf = 1000034000;
typedef vector<ll> vecl;
typedef vector<int> veci;
typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    string S;
    cin >> S;
    bool ok = false;
    string T;
    for (int i = 0; i < S.size(); i++)
    {
        for (int j = 0; j < S.size();j++)
        {
            T = S;
            T.erase(i,j);
            if (T == "keyence")
            {
                ok = true;
            }
            //cout << T << endl;
        }
    }
    if(ok){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
}
