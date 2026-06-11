#include <iostream>
#include <cstdio>
using namespace std;

int main(void) {
    int N;cin>>N;
    double result = 0.0;
    for (int i = 0; i < N; i++) {
        double x;
        string u;
        cin>>x>>u;
        if (u == "JPY") result += x;
        else result += x * 380000.0;
   }
    printf("%.6f\n", result);
    return 0;
}