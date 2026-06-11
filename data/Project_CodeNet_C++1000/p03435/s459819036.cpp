#include <math.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int floor(long long a, long long b) { return a / b; }
int main() {
    int a,b,c,d,e,f,g,h,i;
    
        cin >> a>>b>>c>>d>>e>>f>>g>>h>>i;
     
    if(a-b==d-e&&d-e==g-h&&b-c==e-f&&e-f==h-i&&a-d==b-e&&b-e==c-f&&d-g==e-h&&e-h==f-i){
        cout << "Yes" << endl;
    }else
        cout << "No" << endl;
    return 0;
}