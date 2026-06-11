#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,y;
    cin >> n >> y;
    int p = y / 1000 - n;
    int x_up = p / 9;
    int y_up = p / 4;
    bool flag = true;
    for(int i=x_up;i>=0;i--){
        int amari = p - 9 * i;
        int Y;
        if(amari % 4 == 0){
            Y = amari / 4;
            int z = n - i - Y;
            if(Y >= 0 && z >= 0){
                cout << i << " " << Y << " " << z << endl;
                flag = false;
                break;
            }
        }
    }
    if(flag){
        cout << -1 << " " << -1 << " "<<-1<<endl;
    }
}