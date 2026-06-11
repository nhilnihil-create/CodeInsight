#include <iostream>
using namespace std;
int main() {
    int A,B,C, X = 0;
    cin>>A>>B>>C;
    X=A+B;
    if(X>=C) {
        cout << "Yes";
    }else cout<< "No";
    return 0;
}