#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<cmath>

using namespace std;

#define rep(i, n) for(long int i = 0; i < n; i++)

int main(){
    long int n, k;
    cin >> n >> k;
    long int ans = 0;
    long int num1 = 0;
    long int num2 = 0;
    if (k % 2 == 0){
        for (long int i = 1; i <= n; i++){
            if (i % k == k / 2){
                num1++;
            }
            if (i % k == 0){
                num2++;
            }
        }
    }else{
        for (long int i = 1; i <= n; i++){
            if (i % k == 0){
                num2++;
            }
        }
    }
    cout << num1*num1*num1 + num2*num2*num2 << endl;
}
