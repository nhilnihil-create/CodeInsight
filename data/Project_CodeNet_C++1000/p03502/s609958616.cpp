#include <bits/stdc++.h>
using namespace std;

int main(){
    long long N;
    cin >> N;

    long long c = N;
    int cnt = 0;
    while(true){
        if(N / 10 == 0) {
            cnt += N % 10;
            break;
        }
        cnt += N % 10;
        N /= 10;
    }

    if(c % cnt == 0) puts("Yes");
    else puts("No");
}