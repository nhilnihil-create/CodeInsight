#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    deque<int> dq(N);
    for(int i = 0; i < N; ++i) cin >> dq[i];
    dq.push_front(0); dq.push_back(0);
    long long sum = 0;
    for(int i = 1; i < N+2; ++i){
        sum += abs(dq[i] - dq[i-1]);
    }
    for(int i = 1; i < N+1; ++i){
        cout << sum - abs(dq[i] - dq[i-1]) - abs(dq[i+1] - dq[i]) + abs(dq[i-1] - dq[i+1]) << '\n';
    }
    return 0;
}