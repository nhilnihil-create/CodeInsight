#include <bits/stdc++.h>
using namespace std;
 
int main(){
    int N, K;
    cin >> N >>K;

    int tmp = 1;
    for (int i = 1; i < K; i++){
        tmp += 2;
    }
    if (tmp <= N){
        cout << "YES" << endl;
    }
    else {
        cout << "NO" << endl;
    }
}