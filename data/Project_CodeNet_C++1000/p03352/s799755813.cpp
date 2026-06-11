#include<bits/stdc++.h>
using namespace std;

int main(){
    int x; cin >> x;
    int max_res=0;
    for(int i=0; i<=1000; i++){
        for(int j=2; j<=1000; j++){
            int tmp = pow(i, j);
            if(tmp <= x && tmp > max_res)
                max_res = tmp;
            if(tmp > x) break;
        }
    }
    cout << max_res << endl;
    return 0;
}