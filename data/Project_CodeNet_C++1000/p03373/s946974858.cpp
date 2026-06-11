#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int ans = a * x + b * y;
    int tmp = 0;
    if(a + b > 2 * c){
        for(int numC = 1; numC <= max(x,y); ++numC){
                if(x < numC){
                    tmp = a * (x - numC) + b * (y - numC) + 2 * c * numC;
                    tmp += a * (numC - x);
                    // cout << ans << endl;
                }else if(y < numC){
                    tmp = a * (x - numC) + b * (y - numC) + 2 * c * numC;
                    tmp += b * (numC - y);
                    // cout << ans << endl;
                }else {
                    tmp = a * (x - numC) + b * (y - numC) + 2 * c * numC;
                    // cout << ans << endl;
                }
            if(tmp < ans){
                ans = tmp;
            }
            else {
                break;
            }
        }
    }    
    cout << ans << endl;
}


