#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
int main(){
    IOS;
    int n;
    cin >> n;
    int four = 0;
    int num=n;
    if(n==1 || n==2 || n==4){
        cout << 4 <<endl;
    }else{
        for(int i=1; i<1000000; i++){
        if(num%2==0){
            num /= 2;
        }else{
            num = (num*3)+1;
        }
        if(num==4){
            four++;
        }
        if(four==2){
            cout << i+1 <<endl; 
            break;
        }
    }
    }
    
}