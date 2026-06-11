#include <iostream>
using namespace std;

bool check(int a, int b, int c) {
    if(a>b) {
        return a > c && c > b;
    } else {
        return a < c && c < b;
    }
}

int main(void){
    // Your code here!
    int a, b, c;
    cin >> a >> b >> c;
   if(check(a, b, c)) cout << "Yes" << endl;
   else cout << "No" << endl;
   return 0;
}
