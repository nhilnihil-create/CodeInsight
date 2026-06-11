#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int c,cd,x;
    cin>>c>>cd>>x;
    if(c>x){
        cout<<"NO";
    }
    else if(c==x){
        cout<<"YES";
    }
    else if(c<x){
        if(c+cd>=x){
            cout<<"YES";
        }
        else{cout<<"NO";}
    }
    return 0;
}
