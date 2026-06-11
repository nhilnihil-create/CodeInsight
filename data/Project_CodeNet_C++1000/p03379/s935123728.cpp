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
    //cout << fixed << setprecision(1);
    int N;
    cin >> N;
    vector<ll> X(N);
    int base = N / 2;
    int f = floor((N-1)/2);
    int s = ceil(N/2);
    for (int i = 0; i < N; i++)
    {
        cin >> X[i];
    }
    vector<ll> Y = X;
    sort(all(Y));
    f = Y[f];
    s = Y[s];
    //cout << f << " " << s << endl;
    for (int i = 0; i < N; i++)
    {
        if(X[i] <= f){
            cout << s << endl;
        }
        else{
            cout << f << endl;
        }
    }
}
