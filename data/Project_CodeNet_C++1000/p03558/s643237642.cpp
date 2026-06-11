#include<iostream>
#include<vector>
#include<deque>

#define INF 1e8

using namespace std;

long long int K;

int main(void) {
    cin>>K;
    vector<int> d(K,INF);
    vector<bool> used(K,0);
    d[1] = 1;
    deque<int> q;
    q.push_front(1);

    while(!q.empty()) {
        int current = q.front();
        q.pop_front();
        if(used[current]) continue;
        used[current] = 1;
        int next = (current+1) % K;
        if(d[next] > d[current] + 1) {
            d[next] = d[current] + 1;
            q.push_back(next);
        }

        next = (current*10) % K;
        if(d[next] > d[current]) {
            d[next] = d[current];
            q.push_front(next);
        }
    }

    cout<<d[0]<<endl;

    return 0;
}
