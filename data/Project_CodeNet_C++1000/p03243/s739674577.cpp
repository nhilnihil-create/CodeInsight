#include <bits/stdc++.h>
using namespace std;

void Show(int s){
    
    int i=1,l,r;
    while(1){
        if(i == 1){
            l = 100;
            r = 111;
        }
        else{
            r = 100 * i + 10 * i + i;
            l = r - 110;
        }
        
        if(l <= s && s <= r){
            cout << i << i << i << endl;
            break;
        }
        i++;
    }
}
int main(void){
  
  int s;
  cin >> s;
  Show(s);
}