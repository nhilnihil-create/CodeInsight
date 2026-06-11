#include <bits/stdc++.h>
using namespace std;


int sumDigits (int n) {
    int sum = 0;
    while (n > 0) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}
int main()
{
    int N;
    cin >> N;

    int min = N;
    for (int i=2; i<N; i++) {
        int sum =  sumDigits(i) + sumDigits(N-i);
        if (sum < min) min = sum;
        
    }
    cout << min << endl;
}
