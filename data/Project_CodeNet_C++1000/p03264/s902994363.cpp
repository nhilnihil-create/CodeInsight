#include <iostream>
using namespace std;
int main () {
int k , e =0,o=0;
cin >> k;
for (int i=1; i<=k; i++){
    if (i%2 == 0){
        e++;
    }
    else {
        o++;
    }
}
cout << (e*o) <<endl;
 }

