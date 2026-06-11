#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main(){
    int N;
    cin >> N;
    int sum = 0;
    vector<int>A(N+2);
    A[0] = 0;
    A[N+1] = 0;
    for(int i = 1; i <= N; i++){
        cin >> A[i];
        sum += abs(A[i]-A[i-1]);
    }
    sum += abs(A[N]);
    for(int i = 1;i <= N; i++){
        cout << sum-(abs(A[i+1]-A[i])+abs(A[i]-A[i-1]))+abs(A[i+1]-A[i-1]) << endl;
    }
}
  
