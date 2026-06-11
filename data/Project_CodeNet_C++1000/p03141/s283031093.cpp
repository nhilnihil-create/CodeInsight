#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
typedef pair<long long, long long> P;
int main(){
    long long N;
    cin >> N;
    vector<long long> A(N), B(N);
    for(int i = 0; i < N; i++) cin >> A[i] >> B[i];
    priority_queue<P> q;
    vector<int> used(N, 0);
    for(int i = 0; i < N; i++){
        q.push(P(A[i] + B[i], i));
    }
    long long a = 0, b = 0;
    int flag = 0;
    while(!q.empty()){
        P v = q.top();
        q.pop();
        if(flag % 2 == 0) a += A[v.second];
        else b += B[v.second];
        flag++;
    }
    cout << a - b << endl;
}