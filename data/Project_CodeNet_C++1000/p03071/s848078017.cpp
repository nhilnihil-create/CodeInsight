#include <iostream>
using namespace std;

int main() {
    int a,b,x=0;
    cin >> a >> b;
    if(a < b){
        x += b;
        b--;
    }else{
        x += a;
        a--;
    }
    if(a < b){
        x += b;
        b--;
    }else{
        x += a;
        a--;
    }
    cout << x << endl;
}