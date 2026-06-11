#include <iostream>
#include <string>
using namespace std;

int main(){
    int d;
    cin >> d;
    string ans = "Christmas";
    for(int i = 24; i >= d; i--) ans += " Eve";
    cout << ans << endl;
    return 0;
}