#include<bits/stdc++.h>
using namespace std;
int main(){
    long long int n,sum,m;
    cin>>n;
    sum=0;
    for (int i=1;i<sqrt(n);i++)
     { if (n%i==0)
        { m=(n/i)-1;
          if (m-i>0)sum+=m;
        }
         
     }
     cout<<sum;
    return 0;    
}