#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,A;
    cin >> N >> A;
    int ans = N % 500;
    if(A >= ans){
        cout << "Yes" << '\n';
    }else{
        cout << "No" << '\n';
    }
    return 0;
}