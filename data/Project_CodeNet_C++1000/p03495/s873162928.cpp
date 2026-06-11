#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int main(){
    int N, K;
    cin >> N >> K;
    vector<int> A(N);
    vector<int> cnt(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        cnt[A[i] - 1]++;
    }
    priority_queue<int,vector<int>, greater<int>> q;
    for(int i = 0; i < N; i++){
        if(cnt[i] > 0) q.push(cnt[i]);
    }
    int ans = 0;
    while(q.size() > K){
        ans += q.top();
        q.pop();
    }
    cout << ans << endl;
}