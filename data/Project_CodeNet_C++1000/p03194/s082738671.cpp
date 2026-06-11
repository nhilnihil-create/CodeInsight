#include <iostream>
#include <cmath>
using namespace std;
int main(void){
    // Your code here!
    unsigned long long int N, P;
    cin >> N;
    cin >> P;
    
    if (N==1) {
        cout << P << endl;
        return 0;
    }
    if (P==1) {
        cout << 1 << endl;
        return 0;
    }
    unsigned long long int ans = 1;
    
    unsigned long long int d = 0;
    unsigned long long int p = P;
    unsigned long long int temp;
    for(unsigned long long int i=2; pow(i, N)<=p; i++){
        temp = pow(i, N);
        while(p%temp==0){
            ans *= i;
            p = p/temp;
        }
    }

    cout << ans << endl;
}
