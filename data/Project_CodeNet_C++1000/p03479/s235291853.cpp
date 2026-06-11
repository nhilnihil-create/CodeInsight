#include <iostream>
using namespace std;

long long X, Y, A, Z;

int main() {
    cin>>X>>Y;
    long long i = X;
    while(i<=Y) {
        Z++;
        i=i*2;
    }
    cout<<Z<<endl;
}
