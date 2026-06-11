#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    int da=0,db=0,dc=0;
    for (int i=0;i<n;++i){
        int a,b,c;
        cin >> a >> b >> c;
        int na=max(db,dc)+a;
        int nb=max(da,dc)+b;
        int nc=max(da,db)+c;
        da=na,db=nb,dc=nc;
    }
    cout << max(da,max(db,dc));
}