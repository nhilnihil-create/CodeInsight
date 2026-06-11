#include <iostream>
using namespace std;

int main(void) {
    string a;
    string b;

    std::cin >> a >> b;

    if (a[0] == b[2] ){
        if(a[1] == b[1]){
            if(a[2] == b[0]){
                cout << "YES" << endl;
            }else{
                cout << "NO" << endl;
            }
        }else{
                cout << "NO" << endl;
            }
    }else{
        cout << "NO" << endl;
    }

    return 0;
}