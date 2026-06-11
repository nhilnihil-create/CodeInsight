//Two Integers
#include <bits/stdc++.h>
using namespace std;

int main(){
    int X,Y;
    cin>>X>>Y;
    if(X%Y==0||X>10e18)  cout<<-1<<endl;
    else                 cout<<X<<endl;
    return 0;
}