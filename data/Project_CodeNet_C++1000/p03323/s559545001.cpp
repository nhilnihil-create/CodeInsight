#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int a,b;
    cin >> a >> b;

    if(a <= 8 && b <= 8)
        cout << "Yay!" <<endl;
    else
        cout << ":(" <<endl;

    return 0;
}
