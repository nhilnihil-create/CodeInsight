#include<iostream>
#include<string>
using namespace std;
int main() {
    int N, x=0;
    cin >> N;
    int t = N;
    for(int i = 0; i < 9; i++){
        x += t % 10;
        t /= 10; 
    }  

    if(N % x == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}