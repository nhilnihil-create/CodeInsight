#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N, K, a = 1, i;
    cin >> N >> K;
    
    for(i = 0; i < N; i++){
        if(a * 2 <= a + K)
        a = a * 2;
        
        else
        a = a + K;
    }
    cout << a << endl;
}
