#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int Max = max({a,b,c}), mi = min({a,b,c}), mid = a + b + c - Max - mi;
    int rsl = Max - mid;
    int n_ = rsl + mi;
    if((Max - n_)%2==0){
        cout << (Max - n_) / 2 + rsl << endl;
    }else{
        cout << (Max - n_) / 2 + 2 + rsl << endl;
    }
    return 0;
}