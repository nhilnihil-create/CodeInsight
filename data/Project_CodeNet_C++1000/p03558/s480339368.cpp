#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

#define Rep(b, e, i) for(int i = b; i <= e; i++)
#define rep(n, i) Rep(0, n-1, i)

typedef long long ll;
typedef pair<int, int> P;
typedef std::priority_queue<int> IntPrioQueue; //Z->A
typedef std::priority_queue<int, std::vector<int>, std::greater<int> > IntReversePrioQueue; //A->Z

const int MAX = 200000;
const double PI = 3.14159265358979323846;
const double EPS = 1e-12;
const int INF = 1<<29;
const int MOD = 1000000007;

bool visited[MAX];

//abc077d
//0-1bfs
void solve(void){
    int K, ans = INF;
    cin >> K;
    deque <P> dq;
    memset(visited, false, sizeof(visited));
    dq.push_front(P(1,1));
    while (!dq.empty()) {
        P next = dq.front();
        dq.pop_front();
        visited[next.first] = true;
        if (next.first%K==0) {
            ans = next.second;
            break;
        }
        if (!visited[(next.first+1)%K]) {
            dq.push_back(P((next.first+1)%K, next.second+1));
        }
        if (!visited[(next.first*10)%K]) {
            dq.push_front(P((next.first*10)%K, next.second));
        }
    }
    cout << ans << endl;
}

int main(void){
  solve();
  return 0;
}
