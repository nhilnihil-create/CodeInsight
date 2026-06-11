#include <iostream>

using namespace std;

int main(){
    long long x,y;
    cin >> x >> y;
    long long sum = 0;
    for(long long i = x; i <= y; i*=2)sum++;
    cout << sum <<endl;
}
