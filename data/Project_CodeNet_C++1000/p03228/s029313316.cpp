#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long int;

int main(){
    int a, b, k; cin >> a >> b >> k;
    int cnt = k;
    while(true){
        a /= 2;
        b += a;
        cnt -= 1;
        if(cnt == 0){break;}
        b /= 2;
        a += b;
        cnt -= 1;
        if(cnt == 0){break;}
    }
    cout << a << " " << b << endl;
    return 0;
}