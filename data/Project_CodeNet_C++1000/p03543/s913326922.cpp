#include <bits/stdc++.h>
using namespace std;
int main(){
    int a;
    cin >> a;
    
    int on=a/1000;
    int tw=  (a%1000) /100;
    int th = (a%100)/10;
    int fo = a-(on*1000+tw*100+th*10);
    
    
    if(on== tw&& tw == th)
    {
        cout << "Yes" << endl;
    }
    else if(tw == th && th == fo)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    
}
