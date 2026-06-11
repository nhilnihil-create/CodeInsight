#include<bits/stdc++.h>
using namespace std;
int  a[100];
void revNum(int n)
{
    for(int i=0; i<3; i++)
    {
        a[i] = n%10;
        n /= 10;
    }
}

int main()
{
    int n,x,reversedNumber = 0, remainder;;
    cin>>n;

    while(1){
       revNum(n);
       if(a[0] == a[1] && a[1] == a[2] && a[0]==a[2]){
           cout<<n;
           break;
       }else{
           n++;
       }

    }

    return 0;
}
