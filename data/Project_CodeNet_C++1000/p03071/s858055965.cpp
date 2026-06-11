#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin >> a >> b;

    int c = 0;

    for(int i = 0;i < 2 ;i++){
        if(a <= b){
            c = c + b;
            b = b - 1;
        }    
        else{
                 c = c + a;
                 a = a - 1;

            }
           
    }
    
    cout << c << endl;

}