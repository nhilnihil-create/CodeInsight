#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main(){
    int N;
    cin >> N;

    if(N == 3){
        cout << "2 5 63" << endl;
        return 0;
    }

    N -= 4;
    int x = 2, y = 2, z = 0;

    if(N % 2 == 1){
        z += 1;
        N--;
    }

    x += min(9998, N);
    N = max(0, N - 9998);
    y += min(4998, N);
    N = max(0, N - 4998);
    z += N;

    //cout << x << " " << y << " " << z << endl;

    for(int i = 1; i <= 30000; i++){
        if(i % 6 == 0){
            if(z > 0){
                z--;
                cout << i << " ";
            }
        }
        else if(i % 3 == 0 && y > 0){
            if(y > 0){
                y--;
                cout << i << " ";
            }
        }
        else if(i % 2 == 0 && x > 0){
            if(x > 0){
                x--;
                cout << i << " ";
            }
        }
    }

    cout << endl;
    return 0;
}