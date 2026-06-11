#include <iostream>
using namespace std;

int main(){
    int d, n;
    cin >> d >> n;

    cout << (n == 100 ? 101 : n);

    if(d==0){
        cout << endl;
        return 0;
    } else if (d==1) {
        cout << "00";
    } else if (d==2) {
        cout << "0000";
    } else {
        cout << "000000";
    }

    cout << endl;

    return 0;
}