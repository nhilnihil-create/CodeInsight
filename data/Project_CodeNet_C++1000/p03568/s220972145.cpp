#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N; cin >> N;
    int num = 1;
    for(int i = 0; i < N; ++i) num *= 3;
    int num2 = 1;
    for(int i = 0; i < N; ++i) {
        int a; cin >> a;
        if(a%2 == 0) num2 *= 2;
    }
    cout << num - num2 << endl;
    return 0;
}