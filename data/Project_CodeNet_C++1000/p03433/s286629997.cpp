#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N, A;
    cin >> N >> A;
    
    int i = N / 500;
    int j = N - (500 * i);
    
    if ( A >= j)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
}
