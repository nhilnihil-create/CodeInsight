#include <iostream>
using namespace std;

int main(){
    int N;
    int A;
    cin >> N >> A;
    
    if ( N % 500 <= A) {
        cout << "Yes" << endl;
    }
    
    if ( N % 500 > A) {
        cout << "No" << endl;
    }
    // Your code here!
    
}