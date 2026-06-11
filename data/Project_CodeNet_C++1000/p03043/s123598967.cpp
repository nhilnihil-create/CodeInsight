#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <math.h>
using namespace std;
int N,K;
int main(){
    cin >> N >> K;
    double an=0;
    for(int i=1;i<=N;i++){
        int count = 0;
        int j =i;
        while(j<K){
            j *= 2;
            count++;
        }
        double rui =pow(0.5,count);
        double n = 1/(double)N;
        an = an + n * rui;
    }
    printf("%.12lf\n",an);
}