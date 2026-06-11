#include<iostream>
#include<stdio.h>

using namespace std;

int N,H,W;
int main(){
    cin >> N >> H >> W;
    cout << ( max( 0,(N - W + 1) ) * max( 0, ( N - H + 1))) << endl;
    return 0;
}
