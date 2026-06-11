/*
      author  : nishi5451
      created : 14.08.2020 20:36:51
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int vecx=x2-x1;
    int vecy=y2-y1;
    complex<int> vec(vecx,vecy);
    complex<int> z(0,1),r;
    r = vec*z;
    cout << x2+r.real() << " " << y2+r.imag() << " " << x1+r.real() << " " << y1+r.imag() << endl;



    return 0;
}