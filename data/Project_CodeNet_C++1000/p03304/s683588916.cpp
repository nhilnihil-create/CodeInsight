#include<iostream>
#include<cstdio>

using namespace std;

int main(){
    double n, m, d;
    cin >> n >> m >> d;
    if(d>=n){
        printf("%.08lf\n", (double) 0);
    }
    else if(2*d>=n || d == 0){
        printf("%.08lf\n", (m-1)*((double)1/n));
    }
    else{
        printf("%.08lf\n", (m-1)*((1/n)*(2*d)/n + (2/n)*((n-2*d)/n)));
    }
}