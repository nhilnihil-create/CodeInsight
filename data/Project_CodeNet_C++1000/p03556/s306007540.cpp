#include <iostream>
using namespace std;
int main(void){
    long int n,hantei;
    cin >> n;
    for(long int i=1;;i++){
        if(i*i > n){
            hantei = i-1;
            break;
        }
    }
    cout << hantei * hantei << endl;
}