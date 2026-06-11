#include <bits/stdc++.h>
using namespace std;
int main(void){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    
    int x_side = x2 - x1;
    int y_side = y2 - y1;
    
    cout << x2 - y_side << " " << y2 + x_side << " " << x1 - y_side << " " << y1 + x_side;
   
    return 0;
}
