#include <bits/stdc++.h>
#include <numeric>
using namespace std;
#define ll long long
#define mod 100000007
#define rep(i, n) for (int i = 0; i < n; ++i)
using Graph = vector<vector<int>>;
#define grepq priority_queue<double, std::vector<double>, std::greater<double>>
#define all(v) v.begin(),v.end()
ll INF = 10010001010;

ll lcm(ll a,ll b)
{
    return a * b / __gcd(a, b);
}
typedef tuple<string, int, int> TUP;

bool tuplesort(const TUP &right, const TUP &left)
{
    if (get<0>(right) != get<0>(left))
    {
        return get<0>(left) < get<0>(right);
    }
    if (get<1>(left) != get<1>(right))
    {
        return get<1>(left) > get<1>(right);
    }
    return get<2>(left) < get<2>(right);
}

ll findSumOfDigits(ll n)
{
    ll digit = 0;
    while (n > 0)
    {
        digit++;
        n /= 10;
    }
    return digit;
}
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main(){
    int N;
    string S;
    cin >> N >> S;
    int point = 0;
    int ans = 0;
    for (point = 0; point < N; point++)
    {
        string s, t;
        for (int i = 0; i < point;i++)
        {
            s.push_back(S[i]);
        }
        for (int i = point; i < N;i++)
        {
            t.push_back(S[i]);
        }
        sort(all(s));
        sort(all(t));
        s.erase(unique(all(s)), s.end());
        t.erase(unique(all(t)), t.end());
        int pre = 0;
        string r;
        for (int i = 0; i < s.size(); i++)
        {
            for (int j = 0; j < t.size();j++)
            {
                if(s[i] == t[j]){
                    pre++;
                    r.push_back(s[i]);
                }
            }
        }
        sort(all(r));
        r.erase(unique(all(r)), r.end());
        pre = r.size();
        ans = max(ans, pre);
    }
    cout << ans << endl;
}
