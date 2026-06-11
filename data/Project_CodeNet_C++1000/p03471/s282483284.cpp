#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    int y;
    cin >> y;
    int a,b,c;
    c=y/1000;
    if(c<n){
        cout << -1 << " " << -1 << " " << -1;
        return 0;
    }
    if(c==n){
        cout << 0 << " " << 0 << " " << c;
        return 0;
    }
    b=min((c-n)/4,c/5);
    c-=5*b;
    a=b+c-n;
    b-=2*a;
    if(b<0){
        cout << -1 << " " << -1 << " " << -1;
        return 0;
    }
    cout << a << " " << b << " " << c;
}