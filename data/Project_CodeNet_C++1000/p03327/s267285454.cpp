#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    if(1 <= n && n <= 999)
        cout << "ABC" << endl;
    else 
        cout << "ABD" << endl;

    return 0;
}