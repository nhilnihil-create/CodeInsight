#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int N, M;
    cin >> N >> M;
    typedef pair<long long, int> AB;
    priority_queue<AB, vector<AB>, greater<AB>> que;
    for(int i=0; i<N; i++){
        long long A;
        int B;
        cin >> A >> B;
        que.push(AB(A,B));
    }

    int count = 0;
    long long sum_cost = 0;
    while(true){
        AB vals = que.top(); que.pop();
        long long cost = vals.first;
        int max_n = vals.second;

        int buy_n = min({max_n, M-count});
        count += buy_n;
        sum_cost += (long long)buy_n*cost;

        if(count == M){
            break;
        }

    }

    cout << sum_cost <<endl;
    return 0;

}