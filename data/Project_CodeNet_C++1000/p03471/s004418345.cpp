#include <bits/stdc++.h>
using namespace std;
using ull = unsigned long long;


int main(void)
{
    int N, Y;
    cin >> N >> Y;
    
    Y /= 1000;

    int x = 0;
    int y = 0;
    int z = 0;
    int val = 0;
    bool found = false;
    for(x = 0; x <= N; x++){
        for(y = 0; y <= N; y++){
            z = N - x - y;
            if(z < 0) continue;
            val = 10 * x + 5*y + z;
            
            if(val == Y) {
                found = true;
                break;
            }
        }
        if(val == Y) break;
    }

    if(found){
        cout << x << " " << y << " " << z << endl;
    } else {
        cout << "-1 -1 -1" << endl;
    }
    
    return 0;
}
