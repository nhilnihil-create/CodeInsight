#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>
#include <set>

using namespace std;

//#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ; //何もしない文
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#define pb push_back
#define eb emplace_back

//#define int long long

typedef long long LL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

vector<pair<int,LL>> adjlist[101010];
vector<LL> dist(101010);
bool used[101010];
bool flag = 0;

void bfs(int i)
{
    dump(i)
    queue<int> que;
    //LL dist[101010];
    //REP(j,101010) dist[j] = -LINF;
    dist[i] = 0;
    used[i] = true;
    que.push(i);

    //for(auto p : adjlist[i])
    //{
    //    que.push(p.first);
    //    dump(p.first)
    //}
    while(!que.empty())
    {
        int p = que.front(); que.pop();
        dump(p)
        used[p] = true;
        for(auto r : adjlist[p]){
            if(dist[r.first] == -LINF)
            {
                dist[r.first] = dist[p] + r.second;
                //que.push(make_pair(make_pair()))
                que.push(r.first);
            }
            else
            {
                if(dist[r.first] != dist[p]+ r.second)
                {
                    flag = 1;
                    return ;
                }
            }
        }


    }
}

signed main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;
    REP(j,101010) dist[j] = -LINF;

    REP(i,101010) used[i] = false;
    REP(i,M)
    {
        int L,R; LL D;
        cin>>L>>R>>D;
        L--; R--;
        adjlist[L].emplace_back(R,D);
        adjlist[R].emplace_back(L,-D);
    }
    REP(i,N)
    {
        if(used[i] == true) continue;

        bfs(i);
        if(flag == 1)
        {
            cout << "No" << endl;
            return 0;
        }

    }
    cout << "Yes" << endl;




}