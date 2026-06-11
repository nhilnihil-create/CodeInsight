#include<iostream>
#include<cstdio>
#include<algorithm>
#include<complex>
using namespace std;


int n, a[100000];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    double m = 1000000000;
    sort(a, a+n);
    int x = a[n-1];
    int y = 0;
    for(int i = 0; i < n-1; i++){
        if(abs((double)x/2 - a[i]) < m){
            y = i;
            m = abs((double)x/2 - a[i]);
        }
    }
    printf("%d %d\n", x, a[y]);
}