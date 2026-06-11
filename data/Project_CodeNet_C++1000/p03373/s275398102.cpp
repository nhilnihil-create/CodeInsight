#include <iostream>
#include <algorithm>
using namespace std;
int main(void){
    // Your code here!
    int a, b, c, x, y;
    
    cin >> a >> b >> c >> x >> y;
    
    int smallest = 1e9;
    
    for(int i = 0; i <= 200000; i += 2){
        int sum;
        int tmp1 = x - i / 2;
        int tmp2 = y - i / 2;
        int lackOfA = 0;
        int lackOfB = 0;
        if(i / 2 < x){
            lackOfA = x - i / 2;
        }
        if(i / 2 < y){
            lackOfB = y - i / 2;
        }
        
        sum = i * c + lackOfA * a + lackOfB * b;
        
        smallest = min(smallest, sum);
    }
    cout << smallest << endl;
}
