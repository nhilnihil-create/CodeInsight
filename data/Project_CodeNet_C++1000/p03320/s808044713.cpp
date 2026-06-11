#include <bits/stdc++.h>

using namespace std;
long long m = 1, num = 1;
int k;
long double chet(long long x){
    int sum = 0;
    while(x > 0){
        sum += (x % 10);
        x /= 10;
    }
    return sum;
}
int main(){
    cin >> k;
    for(int i = 1; i <= k; i++){
        cout << num << '\n';
        long long f = num + m, s = num + m * 10;
        if(f / chet(f) <= s / chet(s)){
            num = f;
        }
        else{
            m *= 10;
            num = s;
        }
    }
}
