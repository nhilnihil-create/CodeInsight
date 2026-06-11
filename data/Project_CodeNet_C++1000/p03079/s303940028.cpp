#include <iostream>
using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    if(A + B <= C || A + C <= B || C + B <= A || A != B || B != C || C != A){
        cout << "No" << endl;
    }
    else cout << "Yes" << endl;
}
