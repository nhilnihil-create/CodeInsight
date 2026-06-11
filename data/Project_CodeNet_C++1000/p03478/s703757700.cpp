#include <iostream>
using namespace std;

int func(int x){
    if (x<10) return x;
    return func(x/10)+x%10;
}
int main() {
    int N, A, B, sum=0;
    cin >> N >> A >> B;
    for (int i=0; i<=N; i++){
        if (A<=func(i) && func(i)<=B) sum+=i;
    }
    cout << sum << endl;
}
