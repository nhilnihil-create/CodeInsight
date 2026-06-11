#include<bits/stdc++.h>
using namespace std;

int func(int a){
    int sum = 0;
    while(a > 0){
        sum += a % 10;
        a /= 10;
    }
    return sum;
}

int main(){
    int N, A, B;
    cin >> N >> A >> B;
    int ans = 0;
    for(int i = 0; i <= N; i++){
        if(func(i) >= A && func(i) <= B){
            ans += i;
        }
    }
    cout << ans << endl;
    return 0;
}