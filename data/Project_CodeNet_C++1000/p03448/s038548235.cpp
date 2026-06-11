#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a;
    int b;
    int c;
    int m;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> m;
    int ans = 0;
    
    for (int x = 0;x < a+1;x++){
        for (int y = 0;y < b+1;y++){
            for (int z = 0;z < c+1;z++){
                if (x*500+y*100+z*50 == m){
                    ans ++;
                } 
            }
        }
    }
    
    cout << ans << endl;
}
