#include <iostream>

using namespace std;

int main(){
    long int n, i;
    cin >> n;

    for(i=4;i<=n/16;i+=2){
        if(i%n==0){
            cout << i << endl;
            break;
        }
    }
    if(n%2==0){
        cout << n << endl;
    } else {
        cout << n*2 << endl;
    }

    return 0;
}
