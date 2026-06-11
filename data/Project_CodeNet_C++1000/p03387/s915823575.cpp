#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >> a >> b >> c;
    int p = min(min(a,b),c);
    int q = max(max(a,b),c);
    int r = a+b+c-p-q;
    a=p;b=r;c=q;
    //cout << a << " " << b << " " << c << endl;
    p = c - b;
    q = c - a;
    r = b - a;
    if(p%2==0&&q%2==0) {
        cout << p/2 + q/2 << endl;
        return 0;
    }
    else if(p%2==0){
        cout << p/2 + (q+1)/2 + 1 << endl; 
    }else if(q%2==0){
        cout << (p+1)/2 + q/2 + 1 << endl;
    }else{
        cout << p/2 + q/2 + 1 << endl;
    }
}