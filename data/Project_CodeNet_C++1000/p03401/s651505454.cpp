#include <iostream>
#include <algorithm>

using namespace std;

int gain(int pre, int cur, int post){
    return abs(pre - cur) + abs(cur - post) - abs(pre - post);
}

int main(){
    int N;
    cin >> N;
    int A[N+2]; A[0] = 0;
    int total = 0;

    for(int i=1; i<=N; i++) {
        cin >> A[i];
        total += abs(A[i] - A[i-1]);
    }
    A[N+1] = 0;
    total += abs(A[N]);
    for(int i=1; i<=N; i++){
        cout << total - gain(A[i-1], A[i], A[i+1]) << endl;;
    }
    return 0;
}