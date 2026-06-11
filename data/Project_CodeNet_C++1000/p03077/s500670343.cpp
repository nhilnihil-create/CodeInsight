#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    long long n, a, b, c, d, e;
    cin >> n >> a >> b >> c >> d >> e;
    
    long long mini = min({a, b, c, d, e});

    long long bn = (n - 1) / mini + 1;

    cout << bn + 4 << endl;
}