#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,h,w,a,b,c;
    cin >> n >> h >> w;
    a=n-h+1;
    b=n-w+1;
    c=a*b;
    cout << c << endl;
    return 0;
}
