#include<iostream>
using namespace std;
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    long long n,m;
    cin >> n >>m;
    cout << abs((n-2) * (m-2)); //only inside squares get flipped, edges & corner remains same
}