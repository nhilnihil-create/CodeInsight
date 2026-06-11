#include <bits/stdc++.h>
using namespace std;
 
int main() {
    //偶数か奇数か判断
    int a,b;
    
    cin >> a >> b;
    
    if((a % 2 != 0) && (b % 2 != 0)){
        cout << "Odd" << endl;
    }else{
        cout << "Even" << endl;
    }
     
     return 0;
}