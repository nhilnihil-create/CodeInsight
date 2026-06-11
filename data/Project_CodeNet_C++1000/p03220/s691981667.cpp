#include <iostream>
#include <algorithm>
#include <climits>
#include <cmath>
using namespace std;
int main(void){
    
    int N;
    int T, A;
    cin >> N;
    cin >> T >> A;
    
    int ans = 0;
    int index = INT_MAX;
    
    for(int i = 1; i <= N; i++){
        int H;
        cin >> H;
        double ave_Temp = T * 1000 - H * 6;
        if(index > abs(A*1000 - ave_Temp)){
            index = abs(A*1000 - ave_Temp);
            ans = i;
        }
    }
    
    cout << ans << endl;

}
