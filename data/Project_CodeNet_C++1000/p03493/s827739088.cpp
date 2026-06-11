#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
using namespace std;
int main() {
    int s;
    cin >> s ;
    int num;
    num =0;
    num = (s / 100) + ( (s - (s/100)*100) /10 ) + (s - (s/100)*100 - ( (s - (s/100)*100) /10 )*10 );
    cout << num << endl;
}