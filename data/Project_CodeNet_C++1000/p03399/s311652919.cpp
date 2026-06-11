#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int a,b,c,d,e;
    cin>>a>>b>>c>>d;
    if(a>=b){
        e= e+b;
    }
        else{
        e= e+a;
        }
        if(c>=d){
        e= e+d;
    }
        else{
        e= e+c;
    }
    cout<<e<<endl;
}