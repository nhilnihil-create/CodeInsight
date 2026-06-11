#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> P;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define Rep(i, k, n) for (int i = k; i < (int)(n); i++)
#define RRep(i, k, n) for (int i = k; i > (int)(n); i--)
#define COUT(x) cout << #x << " = " << (x) << " (L" << __LINE__ << ")" << endl
#define ALL(a)  (a).begin(),(a).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
const int MOD = 1000000007;
const double PI = acos(-1); //3.14~
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

int main()
{
    int n, k; cin >> n >> k;
    string S; cin >> S;
    vector<int> num;
    if (S[0] == '0') num.push_back(0);
    for(int i = 0; i < S.size();)
    {
        int j = i;
        while(j < S.size() && S[j] == S[i]) j++;
        num.push_back(j - i);
        i = j;
    }
    if (S.back() == '0') num.push_back(0);

    vector<int> s(num.size() + 1, 0);
    rep(i, num.size()) s[i + 1] = s[i] + num[i];

    int ans = 0;
    for(int left = 0; left < s.size(); left += 2)
    {
        int right = left + k * 2 + 1;
        if (right >= s.size()) right = s.size() - 1;
        chmax(ans, s[right] - s[left]);
    }
    cout << ans << endl;
}