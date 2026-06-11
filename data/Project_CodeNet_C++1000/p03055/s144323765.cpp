#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vll = vector<ll>;
using vvll = vector<vll>;
using vvvll = vector<vvll>;
using vs = vector<string>;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repb(i, a, b) for (int i = (a); i < (b); i++)
#define ALL(a) (a).begin(),(a).end()
#define PRINT(V) for(auto v:(V))cout<<v<<" "<<endl
inline int GCD(int a, int b){return b ? GCD(b, a % b) : a;}
const int MOD = 1000000007;

int main()
{
    int N;
    cin >> N;
    vvi node(N);
    vi a(N - 1), b(N - 1);
    rep(i, N-1)
    {
        cin >> a.at(i) >> b.at(i);
        node.at(a.at(i)-1).push_back(b.at(i)-1);
        node.at(b.at(i)-1).push_back(a.at(i)-1);
    }
    int deepest = 0;
    int diameter = 0;
    queue<vi> q;
    q.push({0, 0, 0}); // depth, self, parent
    while (!q.empty())
    {
        vi qf = q.front();
        q.pop();
        deepest = qf.at(1);
        for (auto &e : node.at(qf.at(1)))
        {
            if (e != qf.at(2))
            {
                q.push({qf.at(0) + 1, e, qf.at(1)});
            }
        }
    }
    q.push({0, deepest, deepest}); // depth, self, parent
    while (!q.empty())
    {
        vi qf = q.front();
        q.pop();
        diameter = qf.at(0);
        for (auto &e : node.at(qf.at(1)))
        {
            if (e != qf.at(2))
            {
                q.push({qf.at(0) + 1, e, qf.at(1)});
            }
        }
    }
    diameter++;
    if (diameter % 3 == 2)
    {
        cout << "Second" << endl;
    }
    else
    {
        cout << "First" << endl;
    }
    
}