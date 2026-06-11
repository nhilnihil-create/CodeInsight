#include <iostream>
using namespace std;


int main(){





long long c, x ,a=0;
cin >> x ;

if (x%2==0) {
   x=x/2 ;
   cout << x*x ;}
else {c = x;
    x=x/2+1;
    a=c-x ;
    cout << a*x ;
}





return 0 ;

}
