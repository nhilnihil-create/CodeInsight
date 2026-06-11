#include <bits/stdc++.h>
using namespace std;

int sumnumbers(int x){
    int y = 0;
    while (x > 0){
        y += x % 10;
        x /= 10;
    }
    return y;
}

int main() {
    int N;
    cin >> N;
    int min;
    for(int i = 1; i <= N / 2 + 1; i++){
        int A = i;
        int B = N - i;
        if(i == 1){
            min = sumnumbers(A) + sumnumbers(B);
        }else if(sumnumbers(A) + sumnumbers(B) < min){
            min = sumnumbers(A) + sumnumbers(B);
        }
    }
    cout << min << endl;
    return 0;
}