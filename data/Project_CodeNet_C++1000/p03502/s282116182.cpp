#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

int keta_Sum(int num){
    
    int sum = 0;
    
    // 各桁の計算
    while(num != 0){
        sum += num % 10;
        num /= 10;
    }
    
    return sum;
}


int main(){
    
    int N;
    cin >> N;
    
    int sum = keta_Sum(N);
    
    // ハーシャッド数かどうか判定
    if(N % sum == 0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    
}
