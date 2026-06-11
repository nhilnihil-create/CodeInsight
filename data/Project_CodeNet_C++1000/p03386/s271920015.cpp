#include <bits/stdc++.h>
using namespace std;

int main()
{
       int a,b,k,n;
       cin>>a>>b>>k;
       n=b-a+1;
       if(n>k*2){
        for(int i=0;i<k;i++){
            cout<<a<<endl;
            a++;
        }

        for(int j=b-k+1;j<=b;j++){
        if(a-1!=j)
            cout<<j<<endl;
        }
       }
       else {
       for(int i=a;i<=b;i++)
        cout<<i<<endl;
       }
        return 0;
}