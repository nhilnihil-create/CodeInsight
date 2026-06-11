#include <bits/stdc++.h>
#include <climits>
#include <sstream>
using namespace std;

int main(){
    
    int N,K;
    cin >> N >> K;
    
    long long x[N];
    for(int i = 0; i < N;i++)cin >> x[i];
    
    long long MIN = 1LL << 60;
    for(int i = 0;i + K - 1< N;i++){
        long long left = x[i], right = x[i + K - 1];
        MIN = min(MIN, min(abs(left),abs(right)) + right - left);
    }
    cout << MIN <<endl;
}
