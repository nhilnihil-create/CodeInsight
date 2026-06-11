#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include <queue>
#include <algorithm>
#include <functional>
#include <map>
#include <array>
#include <cmath>
#include <set>
#include <numeric>

using namespace std;

template <typename T>
using TABLE = vector<vector<T>>;

using LONG = long long;
using LVEC = vector<long long>;


#define FOR(i, s, e) for(i = s; i < e; ++i)
#define FOR_INV(i, s, e) for(i = e - 1; i >= s; --i)

long long PRIME = 1e9 + 7;
long long PRIME2 = 998244353;



int main(){
    LONG N;
    cin >> N;

    vector<vector<int>> edges(N);
    int a, b;
    LONG i;

    FOR(i, 0, N-1){
        cin >> a >> b;
        edges[a-1].push_back(b-1);
        edges[b-1].push_back(a-1);
    }

    vector<int> c(N);
    LONG sum = 0;
    FOR(i, 0, N){
        cin >> c[i];
        sum += c[i];
    }

    sort(c.begin(), c.end(), greater<int>());
    sum -= c[0];

    vector<int> d(N);
    int cur_pos = 0;

    queue<int> q;
    q.push(0);

    vector<bool> passed(N, false);
    passed[0] = true;

    while(q.size() > 0){
        int e = q.front();
        q.pop();

        d[e] = c[cur_pos++];
        passed[e] = true;

        for(int& ne : edges[e]){
            if(!passed[ne]){
                q.push(ne);
            }
        }
    }

    cout << sum << endl;
    FOR(i, 0, N){
        cout << d[i] << " ";
    }
}
