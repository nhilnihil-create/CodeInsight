#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int maxt(int x){
    return (x+9)/10 * 10;
}
int maxr(int x){
    return maxt(x)-x;
} 


int main(){

    int a,b,c,d,e;
    
    cin >> a >> b >> c >> d >> e;

    int r; 

    r = maxt(a)+maxt(b)+maxt(c)+maxt(d)+maxt(e);
    r -= max({maxr(a),maxr(b),maxr(c),maxr(d),maxr(e)});

    cout << r << endl;

}
