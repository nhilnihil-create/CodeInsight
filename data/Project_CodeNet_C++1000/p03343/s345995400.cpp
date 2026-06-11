#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, int> P;

const int INF = 1000000009;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;
    int a[2005];
    P p[2005];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        p[i] = P(a[i], i);
    }
    sort(p, p + n);
    bool b[2005]{0};
    int ans = INF;
    for(int t = 0; t < n; t++){
        int d = 0;
        priority_queue<int, vector<int>, greater<int>> que1, que2;
        for(int i = 0; i < n; i++){
            if(b[i]){
                d = 0;
                while(que1.size()) que1.pop();
            }
            else{
                que1.push(a[i]);
                d++;
                if(d >= k){
                    que2.push(que1.top());
                    que1.pop();
                }
            }
        }
        if((int)que2.size() >= q){
            for(int i = 0; i < q - 1; i++) que2.pop();
            ans = min(ans, que2.top() - p[t].first);
        }
        else break;
        b[p[t].second] = true;
    }
    cout << ans << endl;
}
