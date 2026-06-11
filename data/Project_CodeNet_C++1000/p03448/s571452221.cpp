#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int main(){
    int A, B, C, X;
    int ans = 0;
    cin >> A >> B >> C >> X;
    
    for(int i = 0; i <= A; i++){
        for(int j = 0; j <= B; j++){
            
            int nokori = X - (500 * i + 100 * j);
            int c_Cnt = nokori / 50;
            
            if(nokori >= 0 && C >= c_Cnt  && nokori % 50 == 0){
                ans++;
            }
        }
    }
    
    cout << ans << endl;
    
    
}
