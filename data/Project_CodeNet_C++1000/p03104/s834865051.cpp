#include<iostream>

using namespace std;

int main(){
    long long  a, b;
    cin >> a >> b;

    if(b%2!=0)
    {
        if((b+1)%4!=0)
        {
            b = 1;
        }
        else
        {
            b = 0;
        }
    }
    else
    {
        if(b%4!=0)
        {
            b = b ^ 1;
        }
        else
        {
            
        }
        
    }
    
    long long  ans;
    if (a % 2 == 0)
    {
        if(a%4==0)
        {
            a = 0;
        }
        else
        {
            a = 1;
        }
    }
    else
    {
        if((a-1)%4==0)
        {
            a = a - 1;
        }
        else
        {
            a = (a - 1) ^ 1;
        }
    }
    ans = a ^ b;
    cout << ans << endl;
    return 0;
}