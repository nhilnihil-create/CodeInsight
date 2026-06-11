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

typedef tuple<string, int, int> TUP;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<int> l(Q), r(Q);
    vector<int> csum(S.size()+1);
    int sum = 0;
    csum[0] = 0;
    for (int i = 0; i < S.size()-1; i++)
    {
        if(S[i] == 'A' && S[i+1] == 'C'){
            sum++;
            csum[i + 1] = sum;
        }
        else{
            csum[i + 1] = sum;
        }
    }
    for (int i = 0; i < Q; i++)
    {
        int ans = 0;
        cin >> l[i] >> r[i];
        ans = csum[r[i]-1] - csum[l[i]-1];
        cout << ans << endl;
    }
}
