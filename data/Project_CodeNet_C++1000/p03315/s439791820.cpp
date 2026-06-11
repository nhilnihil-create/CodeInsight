#include <iostream>
using namespace std;
int main(void){
    char s[4];
    int think = 0;
    cin >> s;
    for(int i=0;i<4;i++){
        if(s[i] == '+') think ++;
        else think --;
    }
    cout << think << endl;
}
