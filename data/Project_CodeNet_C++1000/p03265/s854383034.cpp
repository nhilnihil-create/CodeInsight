#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int x1 ,y1,x2,y2;
    cin >> x1>>y1>>x2>>y2;
    int a=x2-x1,b=y2-y1;
    int u,i,o,p;
 u=x2-b;
 i=y2+a;
 o=x1-b;
 p=y1+a;
    cout << u<<' '<<i<<' '<<o<<' '<<p<<endl;
}
