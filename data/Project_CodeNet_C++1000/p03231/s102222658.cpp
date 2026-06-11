#include <iostream>
#include <string>
#define ll long long
using namespace std;
int gcd(int n, int m){
    if(m==0){
        return n;
    }
    else{
        return gcd(m, n%m);
    }
}

int main(){
    int z;
    ll x, y;
    string a, b, c;
    cin >> x >> y;
    cin >> a >> b;
    bool same=true;
    z=gcd(x, y);
    for(int i=0; i<a.size(); i+=(x/z)){
        c+=a[i];
    }
    for(int i=0; i<b.size(); i+=(y/z)){
        if(b[i]!=c[i/(y/z)]){
            same=false;
        }
    }
    if(same){
        cout << x*y/z << endl;
    }
    else{
        z=-1;
        cout << z << endl;
    }
}