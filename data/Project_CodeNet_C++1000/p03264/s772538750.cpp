#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[]) {
    int k;
    cin>>k;
    int ans = (k/2)*(k-k/2);
    printf("%d\n", ans);
    return 0;
}