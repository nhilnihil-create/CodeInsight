#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    int x;
    cin >> x;
    vector<bool> flag(1001,false);
    if(x == 1){
        cout <<1 << endl;
        return 0;
    }
    reps(i,2,101){
        int tmp = i;
        while(tmp <= 1000){
            tmp *= i;
            if(tmp <= 1000){
                flag[tmp] = true;
            }
        }
    }

    for(int i = x; i >= 0; i--){
        if(flag[i]){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}
