#include <iostream>
using namespace std;
int main(void){
 
    int N;
    cin >> N;
    
    if(N % 2 == 0) {
        cout << N << endl;
        return 0;
    }
    int ans = 2 * N;
    cout << ans << endl;

}
