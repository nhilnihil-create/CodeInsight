#include<bits/stdc++.h>
using namespace std;

int main (){
    int n ;
    cin >> n ;
    int m = 100 ;

    for (int i = 0 ; i < n ; i ++){
        int a ;
        cin >> a;
        int count = 0 ;

        for (int j = 0 ; j < 100; j++){
            if (a%2 == 0 ){
                count ++;
                a /= 2;
            }
            else{
                break;
            }
        }
        if(m>count){
            m=count;
        }
    }
    cout <<m;
}