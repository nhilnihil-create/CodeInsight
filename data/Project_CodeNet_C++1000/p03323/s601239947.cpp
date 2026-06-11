#include <iostream>
using namespace std;
int main(void){
    int A,B;
    cin >> A >> B;
    string ans;
    if(A <= 8 && B <= 8){
        ans = "Yay!";
    }
    else{
        ans = ":(";
    }
    cout << ans << endl;
}
