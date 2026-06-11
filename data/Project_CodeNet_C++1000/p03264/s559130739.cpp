#include <iostream>
using namespace std;
int main(void){
    
    int K;
    cin >> K;
    
    int ans = 0;
    for(int i = 1; i <= K; i+=2){
        for(int j = 2; j <= K; j+=2){
            ans++;
        }
    }
    
    cout << ans << endl;
}
