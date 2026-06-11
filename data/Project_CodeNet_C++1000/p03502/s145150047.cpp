#include <iostream>
using namespace std;

int main(void){
    int N;
    cin >> N;
    int n = N;
    int total = 0;
    
    do{
        total += (N % 10);
        N /= 10;
    }while(N > 0);
    
    if(n % total == 0) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}