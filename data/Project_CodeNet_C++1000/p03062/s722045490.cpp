#include <bits/stdc++.h>
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
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    //cout << fixed << setprecision(15);
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll ans = 0;
    int count = 0;
    ll mini = 9999999999;
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
        ans += abs(A[i]);
        if(A[i] < 0){
            count++;
        }
        mini = min(mini,abs(A[i]));
    }
    if(count % 2 == 0){
        cout << ans << endl;
    }
    else{
        cout << ans - 2 * abs(mini) << endl;
    }
    //cout << ans << endl;
}
