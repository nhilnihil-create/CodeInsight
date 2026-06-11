#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll exp(int a, int b){

    if (b == 0) return 1;

    return a*exp(a, b-1);
}

int main(){

    ll N;
    cin >> N;
    ll buf;
    buf = N;
    int digit = 0, sum = 0;

    while(buf != 0){
        sum += buf%10;
        buf /= 10;
        digit++;
    }
//    cout << digit << " " << sum << endl;  // debug

    int l = N/(exp(10, digit-1));
    int temp = (l-1) + 9*(digit-1);
//    cout << l << " " << temp << endl;  // debug
    sum = max(sum, temp);

    cout << sum << endl;
    return 0;
}

