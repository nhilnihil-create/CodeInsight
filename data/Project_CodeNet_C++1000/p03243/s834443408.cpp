#include<bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    if(N%111 == 0){
        cout << N <<endl;
    }
    else if(N/100*111 > N) {
        cout << N/100*111 <<endl;
    }
    else {
        cout << N/100*111+111 << endl;
    }
}