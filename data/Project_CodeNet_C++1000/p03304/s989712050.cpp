#include <iostream>
#include <cstdio>
using namespace std;

int main(){
    long double n, m ,d;
    cin >> n >> m >> d;

    if(d == 0){
        printf("%.10Lf\n", (m-1)/n);
    }
    else{
        printf("%.10Lf\n", 2*(n-d)*(m-1)/(n*n));
    }
    return 0;
}