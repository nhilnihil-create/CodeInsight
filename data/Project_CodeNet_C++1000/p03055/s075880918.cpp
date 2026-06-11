//#include <tourist>
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
const int INF = 1e9;
const ll LINF = ll(1e18);
const int MOD = 1000000007;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int Dx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, Dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
#define yes cout << "Yes" << endl
#define YES cout << "YES" << endl
#define no cout << "No" << endl
#define NO cout << "NO" << endl
#define rep(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()
#define debug(v)          \
    cout << #v << ":";    \
    for (auto x : v)      \
    {                     \
        cout << x << ' '; \
    }                     \
    cout << endl;
template <class T>
bool chmax(T &a, const T &b)
{
    if (a < b)
    {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b)
{
    if (b < a)
    {
        a = b;
        return 1;
    }
    return 0;
}
//cout<<fixed<<setprecision(15);有効数字15桁
//-std=c++14
//-std=gnu++17
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
int n;
vector<vector<int>> G;
// treeDFS(親, 現在地, 根から現在地までの距離, 根からの最大の距離, 根から最大の距離となる頂点
void treeDFS(int from, int current, int dist, int &maxDist, int &maxVertex)
{
    // 距離と終点を更新
    if (dist > maxDist)
    {
        maxDist = dist;
        maxVertex = current;
    }

    for (auto to : G[current])
    {
        // 逆流を防ぐ
        if (to == from)
            continue;
        treeDFS(current, to, dist + 1, maxDist, maxVertex);
    }
}

int getTreeDiameter()
{
    //ある点からDFSして最も遠かった点から2回目のDFSする
    //二回目の始点と最も遠い点が直径になる
    int start = 0, end = 0, maxDist = 0;
    treeDFS(-1, start, 0, maxDist, end);
    start = end, end = 0, maxDist = 0;
    treeDFS(-1, start, 0, maxDist, end);
    return maxDist;
    //printf("start: %d, end: %d, diameter: %d\n", start, end, maxDist);
}
int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    G.resize(n);
    if (n == 1)
    {
        cout << "First"
             << "\n";
        return 0;
    }
    for (int i = 0; i < n-1; i++)
    {
        int temp, temp1;
        cin >> temp >> temp1;
        temp--;
        temp1--;
        G[temp].push_back(temp1);
        G[temp1].push_back(temp);
    }
    int dist = getTreeDiameter();
    vector<bool> dp(dist + 1, false);//先手基準
    dp[1] = false;
    dp[2] = true;
    for (int i = 3; i <= dist; i++)
    {
        if(dp[i-1]&&dp[i-2]){
            dp[i]=false;//相手に勝ちを譲らざる追えない時負け
        }
        else{
            dp[i]=true;
        }
    }
    if(dp[dist]){
        cout<<"First"<<"\n";
    }
    else{
        cout<<"Second"<<"\n";
    }
}
