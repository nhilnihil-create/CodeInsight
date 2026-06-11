#include <iostream>
using namespace std;

int main() {
    int a,b,c,count =0;
    cin >> a >> b >> c;
    while(1){
        if(count == c || a > b)break;
        b -= a;
        count ++;
    }
    cout << count << endl;
}