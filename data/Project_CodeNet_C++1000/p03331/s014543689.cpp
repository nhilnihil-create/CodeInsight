#include <iostream>
using namespace std;

int func(int x){
    if (x<10) return x;
    return func(x/10)+x%10;
}
int main() {
    int N, x, MIN=1000000;
    cin >> N;
    for (int i=1; i<N; i++){
        x=func(i)+func(N-i);
        MIN=min(x, MIN);
    }
    cout << MIN << endl;
}
