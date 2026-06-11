#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, const char * argv[]) {
    int k;
    cin>>k;
    int a = k%10;
    int b = (k%100-a)/10;
    int c = (k-k%100)/100;
    int ans = (10-c)*100 + (10-b)*10 + (10-a);
    printf("%d\n", ans);
    return 0;
}