#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using P = pair<int,int>;
using PL = pair<ll,ll>;


int main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    deque<int> dq(n);
    for(int i = 0; i < n; i++)cin >> dq[i];

    for(int i = 0; i <= k; i++) {
        for(int j = 0; j <= k; j++) {
            for(int t = 0; t <= k; t++) {

                if(i + j + t > k)continue;
                auto deq = dq;
                priority_queue<int, vector<int>, greater<int>> que;
                //i : 左から j : 右から

                for(int x = 0; x < i && deq.size(); x++) {
                    que.push(deq.front());
                    deq.pop_front();
                }

                for(int x = 0; x < j && deq.size(); x++) {
                    que.push(deq.back());
                    deq.pop_back();
                }

                for(int x = 0; x < t && que.size(); x++){
                    if(que.top() > 0)continue;
                    que.pop();
                }

                int sum = 0;
                while(que.size()) {
                    sum += que.top();
                    que.pop();
                }

                ans = max(sum, ans);

            }
        }
    }
    cout << ans << endl;
}