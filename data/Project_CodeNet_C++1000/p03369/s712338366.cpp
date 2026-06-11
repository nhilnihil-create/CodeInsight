#include<bits/stdc++.h>


using namespace std;


int main(){
    string order;
    int ramen_price = 700;
    int topping_price = 100;
    int counter =0;

    cin >> order;

    if(order[0] == 'o') counter++;
    if(order[1] == 'o') counter++;
    if(order[2] == 'o') counter++;

    cout<<ramen_price+topping_price*counter<<endl;
}