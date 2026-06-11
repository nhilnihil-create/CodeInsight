#include <bits/stdc++.h>
using namespace std;
#define rep(i,x) for(int i=0;i<x;i++)

int getmd(int a,int b,int c,int d){
    return abs(a-c)+abs(b-d);
}

int main(){
    int d;
    cin >> d;
    if(d==1)    puts("Hello World");
    else{
        int a,b;
        cin >> a >> b;
        cout << a+b << endl;
    }
    
    return 0;
}