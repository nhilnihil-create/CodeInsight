#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int n;
    cin >> n;
    double x;
    while(n!=0){
        x = (double) pow(n,0.5);
        if((int)x*(int)x==n){
            cout << n << endl;
            return 0;
        }
        n--;
    }
    return 0;
}