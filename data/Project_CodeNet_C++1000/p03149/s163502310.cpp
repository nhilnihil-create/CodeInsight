#include <iostream>
#include<iomanip>
#include <climits>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

int main(){
    int one_count = 0;
    int nine_count = 0;
    int seven_count = 0;
    int four_count = 0;
    int N[4];
    for(int i = 0; i < 4; i++){
        cin >> N[i];
    }
    for(int i = 0; i < 4; i++){
        if(N[i] == 1){
            one_count ++;
        }
        if(N[i] == 9){
            nine_count++;
        }
        if(N[i] == 7){
            seven_count ++;
        }
        if(N[i] == 4){
            four_count ++;
        }
    }
    if(one_count == 1 && nine_count == 1 && seven_count == 1 && four_count == 1){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}