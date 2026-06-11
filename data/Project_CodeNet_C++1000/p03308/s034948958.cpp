#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    
    int N;
    cin >> N;
    
    int min_N = 1000000000, max_N = 0;
    for(int i = 0; i < N; i++){
        int A;
        cin >> A;
        min_N = min(min_N, A);
        max_N = max(max_N, A);
    }
    
    int ans = max_N - min_N;
    cout << ans << endl;
    
}
