#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int N ,M ,B;
    cin >> N >> M >> B;
    int ans = N * M;
    if(ans < B){
        cout << ans << endl;
    }
    else{
        cout << B << endl;
    }

   
}
