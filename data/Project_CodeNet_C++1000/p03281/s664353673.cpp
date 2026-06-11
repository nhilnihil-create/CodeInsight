#include<bits/stdc++.h>
using namespace std;

int yakusu(int N){
    int num = 0;
    int i = 1;
    while (pow(i,2) <= N){
        if (N % i == 0){
            if (pow(i,2) == N){
                num += 1;
                break;
            }
            num += 2;
        }
        i += 1;
    }
    return num;
}

int main(){
    int N;
    cin >> N;
    int cnt = 0;

    for (int i=1; i<=N; i++){
        if (yakusu(i) == 8 && i % 2 == 1){
            cnt += 1;
        }
    }
    cout << cnt << endl;
}