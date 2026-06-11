#include <iostream>
using namespace std;

int main(){
    int n, y0;
    cin >> n >> y0;

    int x, y, z = -1;
    for(x = 0; x <= n; x++){
        for(y = 0; x+y <= n; y++){
            if(x*10000+y*5000+(n-x-y)*1000 == y0){
                z = n-x-y;
                break;
            }
        }
        if(z != -1) break;
    }

    if(z == -1){
        x = -1;
        y = -1;
    }

    cout << x << " " << y << " " << z << endl;
    return 0;
}