#include <iostream>
using namespace std;
int main(void){
    int N,Y;
    int x=-1,y=-1,z=-1;
    
    cin >> N >> Y;
    
    bool can = false;
    
    int sum = 0;
    
    for(x=0;x<=N;x++){
        for(y=0;y<=N;y++){
            z = N - (x + y);
            if(z>=0) sum = 10000*x + 5000*y + 1000*z;
            if(sum==Y){
                can = true;
                break;
            } 
        }
        if(can) break;
    }
    
    if(can) cout << x << " " << y << " " << z;
    if(!can) cout << "-1" << " " << "-1" << " " << "-1";
    return 0;
 
}