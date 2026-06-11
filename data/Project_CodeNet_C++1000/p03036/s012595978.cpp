#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int main()
{
    int xi, r, d, x2000, aux;
    aux = 0;
    xi = 0;
    cin >> r >> d >> x2000;
   while(aux < 10){
        xi = r * x2000 - d;
        x2000 = xi;
        cout << xi << endl;
        aux++;
   }
}
