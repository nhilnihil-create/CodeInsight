#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <deque>
#include <climits>
#define endl '\n'
#define ll long long

using namespace std;

int K;
int *dist;

void bfs()
{
    deque<int> quu; quu.push_back(1); dist[1] = 1;
    while(!quu.empty())
    {
        auto cur = quu.front(); quu.pop_front();
        if(cur% K == 0)
            return;
        {
            auto next_value = cur * 10;
            next_value %= K;
            if(dist[next_value] > dist[cur])
            {
                dist[next_value] = dist[cur];
                quu.push_front(next_value);
            }
        }
        
        {
            auto next_value = cur + 1;
            next_value %= K;
            if(dist[next_value] > dist[cur] + 1)
            {
                dist[next_value] = dist[cur] + 1;
                quu.push_back(next_value);
            }
        }
        
    }
    
    return;
}

int main(void)
{
    cin.tie(NULL); ios_base::sync_with_stdio(false);
    cin >> K;
    dist = new int[K+1]();
    for(int i = 0; i < K + 1; i++)
        dist[i] = INT_MAX;
    bfs();
    cout << dist[0] << endl;
    return 0;
}
