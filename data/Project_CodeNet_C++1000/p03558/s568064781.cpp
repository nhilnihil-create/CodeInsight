#include"bits/stdc++.h"
using namespace std;

int main() {
    long long K;
    cin >> K;

    //ダイクストラ法をやる
    vector<long long> cost(K, INT_MAX);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    cost[1] = 1;
    pq.push({ 1, 1 });

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();

        //+1していけるノード
        int plus_one = (top.second + 1) % K;
        if (top.first + 1 < cost[plus_one]) {
            cost[plus_one] = top.first + 1;
            pq.push({ cost[plus_one], plus_one });
        }

        //10倍して行けるノード
        int mult_ten = (top.second * 10) % K;
        if (top.first < cost[mult_ten]) {
            cost[mult_ten] = top.first;
            pq.push({ cost[mult_ten], mult_ten });
        }
    }

    cout << cost[0] << endl;
}