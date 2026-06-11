#include<bits/stdc++.h>
#define MAX 1000000000000000000
using ll = long long;
using namespace std;

int main(){
    ll A, B, C;
    ll K;
    cin >> A >> B >> C >>K;

    if(K%2==1){
        cout << (B-A) << endl;
    }else{
        cout << (A-B) << endl;
    }
    return 0;
}