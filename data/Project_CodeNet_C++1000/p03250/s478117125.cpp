#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    
    int N[3];
    for(int i = 0; i < 3; i++){
        cin >> N[i];
    }
    sort(N, N+3);
    
    int ans = N[2] * 10 + N[1] + N[0];
    cout << ans << endl;
    
}
