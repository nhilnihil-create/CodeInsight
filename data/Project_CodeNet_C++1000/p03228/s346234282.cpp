#include <bits/stdc++.h>
using namespace std;
void takahasi(int &x, int &y){
    if(x%2 ==1){
        x -= 1;
        x /= 2;
        y += x;
    }
    else{
        x /= 2;
        y += x;
    }
}
void aoki(int &x, int&y){
    if(y%2 ==1){
        y -= 1;
        y /= 2;
        x += y;
    }
    else{
        y /=2;
        x += y;
    }
    
}
int main(){
    int a,b,k;
    cin >> a >> b >> k;
    for(int i=1; i<k+1 ; i++){
        if(i%2 == 1){
            takahasi(a,b);
        }
    else{
        aoki(a,b);
    }
    }
    cout << a << " " << b <<endl;
}
    
    