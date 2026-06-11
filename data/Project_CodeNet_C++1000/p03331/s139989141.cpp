#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

int keta_Sum(int num){
    
    int sum = 0;
    while(num != 0){
        sum += num % 10;
        num /= 10;
    }
    
    return sum;
}

int main(){
    
    int N;
    cin >> N;
    
    int ans = INT_MAX;
    for(int A = 1; A < N; A++){
        int A_keta = keta_Sum(A);
        int B_keta = keta_Sum(N - A);
        // 各桁の和を計算いて最小値を求める
        ans = min(ans, A_keta + B_keta);
    }
    
    cout << ans << endl;
    
}
