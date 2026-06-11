#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 1000000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(), v.end()
#define PI acos(-1) 
bool IsPrime(int num)
{
    if (num < 2)
        return false;
    else if (num == 2)
        return true;
    else if (num % 2 == 0)
        return false; // 偶数はあらかじめ除く

    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2)
    {
        if (num % i == 0)
        {
            // 素数ではない
            return false;
        }
    }

    // 素数である
    return true;
}
const ll INF = 10010001010;
const int inf = 2000000000;
ll lcm(ll a, ll b)
{
    return a * b / __gcd(a, b);
}

typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    ll N;
    cin >> N;
    string n = to_string(N);
    bool nine = true;
    bool near = true;
    int ans = 0;
    for (int i = 0; i < n.size(); i++)
    {
        if(n[i] != '9'){
            nine = false;
        }
    }
    for (int i = 1; i < n.size();i++)
    {
        if (n[i] != '9')
        {
            near = false;
        }
    }
    if(nine){
        ans += n.size() * 9;
        cout << ans << endl;
    }
    else{
        if(near){
            ans = n[0] - 48;
            ans += 9 * (n.size() - 1);
            cout << ans << endl;
        }
        else{
            ans = n[0] - 48;
            ans += 9 * (n.size() - 1);

            if (ans >= 10)
            {
                cout << ans - 1 << endl;
            }
            else{
                cout << ans << endl;
            }
        }
    }
}
