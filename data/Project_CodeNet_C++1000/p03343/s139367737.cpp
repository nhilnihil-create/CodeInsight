#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> P;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    int a[2003];
    P p[2003];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        p[i] = P(a[i], i);
    }
    sort(p, p + n);
    int ans = 1000000000;
    int d[2003] {0};
    int c[2003];
    int start;
    for(int i = 0; i < n; i++){
        priority_queue<int, vector<int>, greater<int>> que;
        for(int j = 0; j < n; j++) c[j] = a[j];
        start = 0;
        for(int j = 0; j < n; j++){
            if(d[j]){
                sort(c + start, c + j);
                for(int s = start; s < j - (k - 1); s++) que.push(c[s]);
                start = j + 1;
            }
        }
        sort(c + start, c + n);
        for(int s = start; s < n - (k - 1); s++) que.push(c[s]);
        if((int)que.size() < q) break;
        int les = que.top();
        for(int j = 0; j < q - 1; j++) que.pop();
        int lar = que.top();
        ans = min(ans, lar - les);
        d[p[i].second] = 1;
    }
    cout << ans << endl;
}