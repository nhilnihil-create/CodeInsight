#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    int a = n%1000;
    int b = n/10;
    if(a % 111 == 0 || b % 111 == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
