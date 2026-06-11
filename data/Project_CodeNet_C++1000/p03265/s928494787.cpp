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
const int inf = 2000000000;


typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int X1, Y1, X2, Y2;
    cin >> X1 >> Y1 >> X2 >> Y2;
    int height = abs(Y2 - Y1);
    cout << X2 - Y2 + Y1 << " " << Y2 + X2 - X1 << " " << X1 - Y2 + Y1 << " " << Y1 + X2 - X1 << endl;
}
