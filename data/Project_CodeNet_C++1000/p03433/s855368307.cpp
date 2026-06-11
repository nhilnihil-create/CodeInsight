#include <iostream>
using namespace std;

int main(){
    int N, A;
    cin >> N >> A;

    while(N >= 500){
        N = N - 500;
    }
    if(N <= A){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}