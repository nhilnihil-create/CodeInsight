#include<bits/stdc++.h>
using namespace std;
static const int INFTY = (1 << 21);

int func(int a){
    int sum = 0;
    while(a > 0){
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

int main(){
    int N;
    cin >> N;
    int temp, ans = INFTY;
    for(int i = 1; i < N; i++){
        temp = func(i) + func(N - i);
        ans = min(ans, temp);
    }
    cout << ans << endl;
    return 0;
}