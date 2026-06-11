#include <iostream>
using namespace std;
int main(){
    int a, b, c, d, taka=0;
    cin >> a >> b >> c;
    d=a+b;
    if(d>=c-1){
        taka = c+b;
    }
    else{
        taka = d+b+1;
    }
    cout << taka << endl;
    return 0;
}