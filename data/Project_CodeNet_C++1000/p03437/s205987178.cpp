#include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin >> x >> y;
    if(x % y == 0){
        cout << -1 << endl;
        return 0;
    } else {
        for(int i = 2;i*x <= pow(10,18);i++){
            if((i*x) % y != 0){
                cout << i*x << endl;
                return 0;
            }
        }
        cout << -1 << endl;
        return 0;
    }
}