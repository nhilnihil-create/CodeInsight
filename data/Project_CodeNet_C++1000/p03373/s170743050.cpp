#include <bits/stdc++.h>
using namespace std;
#define LL long long


int main(){
    int a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;
    
    int pizzaC = c * 2;
//    int pizzaAB = a + b;
    int pizzaMax = max(x, y);
    int pizzaMin = min(x, y);
    vector<int> price(3, 0);
    
//    if (pizzaAB <= pizzaC){
        price.at(0) =  (a * x) + (b * y);
//    }else if (pizzaAB > pizzaC){
        
//       if (a > c && b > c){
            while (pizzaMax > 0){
                price.at(1) = price.at(1) + pizzaC;
                pizzaMax --;
            }
//        }else{
             while (pizzaMin > 0){
                price.at(2) = price.at(2) + pizzaC;
                pizzaMin --;
                x --;
                y --;
            }
            price.at(2) = price.at(2) + (a * x) + (b * y);
            
         //   for (int i = 0; i < 3; i++) cout << price.at(i) << endl;
        sort(price.begin(), price.end());
        cout << price.at(0) << endl;
//        }
//    }
    
//    cout << price << endl;
}