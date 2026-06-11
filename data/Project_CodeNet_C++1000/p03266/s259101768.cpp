#include <iostream>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
  // aとbがともにKの倍数である
  // aとbの mod K の和がKの倍数である
  // 2つ目の条件はkが奇数のとき、整数にならないので、そこを場合分けしてる
    if (k % 2 == 0) {
        long long a = n / k;
        long long b = (n + (k/2)) / k;
        cout << a*a*a + b*b*b << endl;
    }
    else {
        long long a = n / k;
        cout << a*a*a << endl;
    }
}