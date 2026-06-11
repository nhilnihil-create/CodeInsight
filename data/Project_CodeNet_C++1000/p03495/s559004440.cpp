#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main() {
    int N, K;
    cin >> N >> K;
    int A[200010]; 
    int num[N+1] = {0};
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        ++num[A[i]];
    }
    int c = 0;
    for(int i = 0; i <= N; i++){
        if(num[i] != 0) c++;
    }
    sort(num, num + N + 1);
    int sum = 0;
    int j = 0;
    for(int i = 0; i <= N; i++){
        if(num[i] != 0){
            if(j >= c - K) break;
            sum += num[i];
            j++;
        }
    }
    cout << sum << endl;

    return 0;
}