#include <bits/stdc++.h>
using namespace std;

int main() {
    int X,Y;
    cin>>X>>Y;
    if(X%Y==0){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=1;;i++){
        if(i*X%Y!=0){
            cout<<i*X;
            return 0;
        }
    }
return 0;}
/*
g++ code.cpp
./a.out
*/