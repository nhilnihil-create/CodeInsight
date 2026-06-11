#include<iostream>
#include<string>
using namespace std;
int main() {
    int N, A, B;
    cin >> N >> A >> B;
    int a, b, c, d, e, x;
    int sum = 0;

    for(int i = 1; i <= N; i++){
        a = i / 10000;
        b = (i - 10000*a) / 1000;
        c = (i - 10000*a - 1000*b)/ 100;
        d = (i - 10000*a - 1000*b - 100*c) / 10;
        e = (i - 10000*a - 1000*b - 100*c - 10*d);
        x = a + b + c + d + e;
        if(A<=x && x <= B) {
            sum += i;
        }
    }

    cout << sum << endl;
    return 0;
}