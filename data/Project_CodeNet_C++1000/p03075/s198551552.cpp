#include <iostream>
using namespace std;

int main(){
    int a, b, c, d, e, k;
    cin >> a >> b >> c >> d >> e >> k;
    bool t = (k < e-a);
    if ( t ){
        cout << ":(" << endl;
    }else{
        cout << "Yay!" << endl;
    }
}