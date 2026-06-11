#include<bits/stdc++.h>
using namespace std;

/*
long Lucas(long n){
    if (n == 0) return 2;
    else if (n == 1) return 1;
    else return (Lucas(n-1) + Lucas(n-2));
}
*/

int main(){
    int N;
    cin >> N;
    vector<long> v(N+1); 
    v.at(0) = 2;
    v.at(1) = 1;
    // cout << Lucas(N) << endl;
    for (int i = 2; i < N+1; i++){
        v.at(i) = v.at(i-1) + v.at(i-2);
    }
    cout << v.at(N) << endl;
}