#include <iostream>
using namespace std;
int main(void){
    int n, a, b; cin >> n >> a >> b;
    if (n >= a + b){
        cout << min(a, b) << " " << 0 << endl;
    }else{
        cout << min(a,b) << " " << a + b - n << endl;
    }
    
}