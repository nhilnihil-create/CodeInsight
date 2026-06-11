#include <bits/stdc++.h>
using namespace std;
// Multiple Gift
typedef pair<int, int> P;

int main(){
    long long X, Y;
    long long a = 0;
    int count = 0;

    cin >> X >> Y;
    a = X;
    while(a <= Y){
        count++;
        a = a * 2;
    }

    cout << count << endl;

    return 0;
}