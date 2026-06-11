#include<bits/stdc++.h>
using namespace std;

int main(){
    long long k,a,b;
    cin >> k >> a >> b;
    if(b-a>2){
        if(k<=a)cout << k+1 << endl;
        else{
            cout << b + (b-a)*((k-a-1)/2) + (k-a+1)%2 << endl;
        }
    }
    else{cout << k+1 << endl;}
    return 0;
}