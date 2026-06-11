#include <iostream>
using namespace std;

int main(){
    int a, b, ans=0;
    cin >> a >> b;
    int x = b-a;
    x--;

    while(x!=0){
        ans += x;
        x--;
    }

    cout << ans - a << endl;

    return 0;
}