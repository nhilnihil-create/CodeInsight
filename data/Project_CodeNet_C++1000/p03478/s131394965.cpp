#include <iostream>

using namespace std;
int main() {
    int n;
    int a, b;
    cin >> n >> a >> b;
    int s = 0;
    for(int i = 1; i <= n;i++){
        int sum = 0;
        sum += (i / 1) % 10;
        sum += (i / 10) % 10;
        sum += (i / 100) % 10;
        sum += (i / 1000) % 10;
        sum += (i / 10000) % 10;
        if(a <= sum && sum <= b){
            s += i;
        }
    }
    cout << s << endl;
}

