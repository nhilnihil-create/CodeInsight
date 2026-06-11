#include<bits/stdc++.h>
using namespace std;
#define ll long long
int prime[100100];

void pgen()
{

    prime[0]=1;
    prime[1]=1;
    for(int i=2; i*i<=100000; i++)
    {
        for(int j=i+i; j<=100000; j+=i)
        {
            prime[j] = 1;
        }
    }


}

int main()
{
    pgen();
    int n;
    cin >> n;
   for(int cnt=1,i=3; cnt<=n; i++)
   {
       if(!prime[i] && i%10==1)
       {
         cout << i << " " ;cnt++;
       }
   }

}
