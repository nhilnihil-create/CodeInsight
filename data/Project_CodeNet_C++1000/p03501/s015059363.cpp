#include <iostream>
using namespace std;

int main (void) {
    int a, b, t;
    cin >> t >> a >> b;

    if(t * a < b){
        cout << t * a << endl;
    }else{
        cout << b << endl;
    }

    return 0;

}
