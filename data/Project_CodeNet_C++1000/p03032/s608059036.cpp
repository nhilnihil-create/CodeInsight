#include<iostream>
#include<list>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    priority_queue<int, vector<int>, greater<int>> pq;
    int lim = min(n, k);
    int maxv = 0;
    for (int i = 0; i <= lim; i++)
    {
        for (int j = 0; j+i <= lim; j++)
        {
            for (int a = 0; a < i; a++)
            {
                pq.push(v[a]);
            }
            for (int b = 0; b < j; b++)
            {
                pq.push(v[n - 1 - b]);
            }
            for (int c = 0; c < k-i-j; c++)
            {
                if(!pq.empty() && (pq.top()<0))
                {
                    pq.pop();
                }
                else
                {
                    break;
                }
            }
            int cnt = 0;
            while (!pq.empty())
            {
                cnt += pq.top();
                pq.pop();
            }
            maxv = max(maxv, cnt);
        }
    }
    cout << maxv << endl;

    return 0;
}