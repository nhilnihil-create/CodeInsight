#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
#define ll long long
const int inf = 1000000000;

int main(){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x=x2-x1,y=y2-y1;
    cout << x2-y << " " <<  y2+x  << " "<< x1-y << " " <<  y1+x << endl;
    return 0;
}