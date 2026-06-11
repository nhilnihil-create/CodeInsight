#include <iostream>
using namespace std;

int sumOfNth(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main(void){
    int n;
    cin >> n;
    
    int ans = 10000000;
    for (int i=1; i<n; i++) {
        int a = i;
        int b = n - a;
        ans = min(ans, sumOfNth(a)+sumOfNth(b));
        
    }
    cout << ans << endl;
}

