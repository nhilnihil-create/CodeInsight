#include<iostream>
using namespace std;
int main(){
    int N,A,P,Q;
    cin >> N >> A;
    P = N / 500;
    Q = N - P * 500;
    if (A >= Q)
    {
        cout << "Yes" << endl;
    }else
    {
        cout << "No" << endl;
    }
    return 0;
    
}