#include <bits/stdc++.h>
using namespace std;

int main(void){
 
    char X,Y;
    cin >> X >> Y;
    
    if((int)X > (int)Y){
        cout << ">" <<endl;
    }
    else if((int)X == (int)Y){
        cout << "=" <<endl;
    }
    else{
        cout << "<" <<endl;
    }
}