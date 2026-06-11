#include <bits/stdc++.h>
using namespace std;

int main() {
    int A , B , C , X ;
    cin >> A >> B >> C >> X ;
    
    //A枚の中からa枚使って払えるのかを考える
    int score=0 ;
    
    for( int a=0 ; a<=A ; a++ ){
        for( int b=0 ; b<=B ; b++ ){
            for( int c=0 ; c<=C ; c++ ){
                int sum = 500*a + 100*b + 50*c ;
                    
                    if( sum==X ){
                        score++ ;
                    }
            }
        }
    }
    
    cout << score << endl;
}

