#include <iostream>
using namespace std;

int main(){
    int N, A, B;
    cin >> N >> A >> B;

    cout << (N - A + 1) * (N - B + 1) << endl;
    
    return 0;
}