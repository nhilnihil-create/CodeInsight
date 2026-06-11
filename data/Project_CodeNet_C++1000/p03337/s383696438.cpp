#include<bits/stdc++.h>
 
using namespace std;

int maior(int a, int b){
    if(a > b) return a;
    return b;
}


int main(){
    int a, b, max;
    cin >> a >> b;
    max = maior(a+b, a-b);
    max = maior(max, a*b);
    cout << max << endl;;
}