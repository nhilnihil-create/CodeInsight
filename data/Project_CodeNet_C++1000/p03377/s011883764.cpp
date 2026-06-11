#include <iostream>
#include <vector>
using namespace std;
int main(){
    int A, B, X;
    cin >> A >> B >> X;
    if(A <= X && X <= A + B){
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
}