#include <iostream>
#include <string>
using namespace std;
int main() {
    int N,A;
    cin >> N;
    cin >> A;
    while(1){
        if(N < 500){
            break;
        }
        N = N - 500;
    }
    
    if(N <= A){
        cout << "Yes" << endl;
    }else{
        cout << "No" <<endl;
    }
}