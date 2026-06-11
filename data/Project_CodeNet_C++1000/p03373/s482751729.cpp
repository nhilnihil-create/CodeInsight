#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <tuple>
#include <cstdio>
#include <set>
#include <queue>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define _GLIBCXX_DEBUG
using namespace std;
// C - Takahashi's Information
int main() {
    int A,B,C;
    cin >> A >> B >> C;
    int X,Y;
    cin >> X >> Y ;
    // A
    int price ;
    int min_price_A = A*X + B*Y;
    for(int i=0;i<= ( 2*X );i=i+2){
        int y ;
        if( (Y - (i/2) ) >= 0 ){
            y= (Y-(i/2));
        }
        else{
            y =0;
        }
        
        price = A*(X-(i/2)) + B*y + C*i ;
        if( min_price_A > price){
            min_price_A = price;
        }
    }
    // B
    int min_price_B = A*X + B*Y;
     for(int i=0;i<= ( 2*Y );i=i+2){
        int x ;
        if( (X - (i/2) ) >= 0 ){
            x= (X-(i/2));
        }
        else{
            x =0;
        }
        
        price = A*x + B*(Y-(i/2)) + C*i ;
        if( min_price_B > price){
            min_price_B = price;
        }
    }
    // 
    int min_price;
    min_price = min(min_price_A,min_price_B) ;
    cout << min_price << endl;
}