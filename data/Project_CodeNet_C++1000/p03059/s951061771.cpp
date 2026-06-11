#include<vector>
#include <iostream>
#include<string>
#include <complex>

using namespace std;

int main(){
    float a, b, t;
    cin >> a;
    cin >> b;
    cin >> t;
    int cnt = 0;
    for(int i= 1; a*i < t+0.5; i++){
        cnt += b;
    }

    cout << cnt << endl;
}