#include <bits/stdc++.h>
using namespace std;
int main() {
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int m=a*x+b*y;

    for(int k=0;k<2*max(x,y)+1;k++){
        int i=max(0,(x-k/2));
        int j=max(0,(y-k/2));

        if(m>a*i+b*j+c*k){
            m=a*i+b*j+c*k;
        }
    }

    cout << m << endl;
}