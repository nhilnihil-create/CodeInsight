#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main() {
    int a,b;
    cin>>a>>b;
    if(a*b==15||a+b==15){
        if(a+b==15){
            cout<<"+"<<endl;
        }
        else{
            cout<<"*"<<endl;
        }
    }
    else{
        cout<<"x"<<endl;
    }
}
