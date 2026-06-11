#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long long n, a, b;
    cin >> n >> a >> b;

    if((b-a) % 2== 0) printf("Alice\n");
    else printf("Borys\n");

    return 0;
}