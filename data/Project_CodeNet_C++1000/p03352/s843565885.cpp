#include <bits/stdc++.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int X;
    cin >> X;
    int high = ceil(sqrt(X));

    int max_val = 0;
    for(int i=high; i>0; i--){
        if(i==1){
            max_val = (max_val < 1)? 1:max_val;
        }
        int max_p = (int)round(log(X)/log(i));
        for(int j=max_p; j>=2; j--){
            int val = (int)round(pow(i, j));
            if(val <= X && max_val < val){
                max_val = val;
            }
        }
    }
    cout << max_val << endl;
    return 0;
}