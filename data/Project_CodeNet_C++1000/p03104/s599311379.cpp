#include <iostream>
using namespace std;
long long f(long long x){
    long long res = 0;
    if(x % 2 == 0){
        if(x / 2 % 2 == 1) res++;
        res ^= x;
    }
    else{
        if((x + 1) / 2 % 2 == 1) res++;
    }
    return res;
}
int main(){
    long long A, B;
    cin >> A >> B;
    if(A == 0){
        cout << f(B) << endl;
        return 0;
    }
    long long ans = f(B)^f(A - 1);
    cout << ans << endl;
}