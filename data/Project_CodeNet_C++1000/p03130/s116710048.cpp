#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[6];
    int x = 0,b = 0,c = 0,d = 0;
    for(int i = 0; i < 6; i++){
        cin >> a[i];
        if(a[i] == 1){
            x++;
        }else if (a[i] == 2){
            b++;
        }else if(a[i] == 3){
            c++;
        }else if(a[i] == 4){
            d++;
        }
    }
    if(x>2||b>2||c>2||d>2){
        cout << "NO" << endl;
    }else{
        cout << "YES" << endl;
    }

    return 0;
}