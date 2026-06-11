#include<iostream>
using namespace std;
int main(){
    int N, fN = 0, n;
    cin >> N;
    n = N;
    while(n > 0){
        fN += n % 10;
        n /= 10;

    }
  
    if(N % fN) cout << "No" << endl;
    else cout << "Yes" << endl;
}