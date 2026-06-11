#include <bits/stdc++.h>
using namespace std;
int main(void){
    int i=0,n,d;
    cin >> d >> n;
    if(d==0 && n==100)
    {
        cout << n+1 << endl;
        return 0;
    }
    if(d==1 && n==100)
    {
        cout << 100*(n+1) << endl;
        return 0;
    }
    if(d==2 && n==100)
    {
        cout << 10000*(n+1) << endl;
        return 0;
    }    
    if(d==0)
    {
        cout << n << endl;
        return 0;
    }
    else if(d==1)
    {
        cout << 100*n << endl;
        return 0;
    }
    else if(d==2)
    {
        cout << 10000*n << endl;
        return 0;
    }
            
        
    return 0;
}
