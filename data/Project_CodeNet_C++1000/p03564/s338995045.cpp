#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
    int N;
    int K;
    int num = 1;
    cin >> N;
    cin >> K;
    rep(i, N){
        if (num * 2 >= num + K){
            num += K;   
        }
        else
        {
            num *= 2;
        }
        
    }
    cout << num << endl;
}