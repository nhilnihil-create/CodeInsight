#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main(void){
    int N;
    cin >> N;

    int num{0};

    for(int i{1}; i<=N; i+=2){
        int yakusu{0};

        for(int j{1}; j<=i; ++j){
            if(i%j == 0){
                ++yakusu;
            }
        }

        if(yakusu==8){
            ++num;
        }

    }
    cout << num << endl;
}
