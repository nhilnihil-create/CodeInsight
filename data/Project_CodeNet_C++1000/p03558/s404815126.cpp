#include <bits/stdc++.h>

using ll = long long;

#define mod 1000000007
#define REP(i, n) for (int i = 0; i < n; i++)
#define INF (1 << 29)

using namespace std;

//long C(long n, long r);
//long long gcd(long long a, long long b);
//long long lcm(long long a, long long b);

int multiple(int k){
    int mul = 0;
    do {
        mul += k % 10;
        k /= 10;
    } while(k != 0);
    return mul;
}

void solve()
{
    int k;
    cin >> k;
    vector<bool> flag(k, false);
    deque<pair<int, int>> dq;
    dq.push_back(make_pair(1, 1));
    while(!dq.empty()){
        auto p = dq.front();
        dq.pop_front();
        int node = p.first;
        int dis = p.second;
        if(flag[node]) continue;
        flag[node] = true;
        if(node == 0) {
            cout << dis << endl;
            return;
        }
        dq.push_back(make_pair((node+1) % k, dis+1));
        dq.push_front(make_pair(node*10%k, dis));
    }

}

int main()
{
    solve();
    return 0;
}
