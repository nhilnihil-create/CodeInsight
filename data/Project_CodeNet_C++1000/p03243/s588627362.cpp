#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i=n; i<=999; i++){
        if( i%10 == (i/10)%10 && i%10 == i/100 ){
            cout << i << endl;
            return 0;
        }
    }

    return 0;
}