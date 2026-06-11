#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int a,b,k;
    cin >> a >> b >> k;
    
    cin >> a >> b >> k;
    if(b - a + 1 < k * 2){
          for(int i = a;i <= b;i++){
                cout << i << endl;
          }
    }else{
          for(int i = 0;i < k;i++){
                cout << a + i << endl;
          }
          for(int i = 0;i < k;i++){
                cout << b - k + 1 + i << endl;
          }
    }
}
