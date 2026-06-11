#include<iostream>
#include<vector>
#include <cmath>
#include <map>
#include <algorithm>
using namespace std;
int main(void){
    int N , K ;
    cin >> N >> K ;
    int a ,b;
    a = N % K ;
    
    if(a != 0){
        cout << 1 << endl;
    }else {
        cout << 0 << endl;
    }

    return 0;
}