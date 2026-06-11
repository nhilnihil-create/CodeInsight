#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq  priority_queue<double, std::vector<double>, std::greater<double>>

    int lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    char B;
    cin >> B;
    if(B == 'A'){
        cout << 'T' << endl;
    }
    else if(B == 'T'){
        cout << 'A' << endl;
    }
    else if(B == 'G'){
        cout << 'C' << endl;
    }
    else{
        cout << "G" << endl;
    }
}
