#include <bits/stdc++.h>
using namespace std;
bool prime[100101];
bool expo[100101];

int pref[100101] ;
void SieveOfEratosthenes( )
{

    prime[0] = true;
    prime[1] = true;

    for (int p=2; p*p<=100100; p++)
    {

        if (prime[p] ==false)
        {

            for (int i=p*p; i<=100100; i += p)
                prime[i] = true;
        }
    }
    expo[0] = true ;
    expo[1] = true ;
    for (int i=2; i<=100100; i++)
       {
           if(!prime[i])
           {
               int r = (i+1)/2;
               if(prime[r])
               expo[i] = true;

           }
           else expo[i] = true;
       }
   for(int i=2; i<=100100; i++)
   {
       if(!expo[i])
        pref[i] = pref[i-1] + 1 ;
       else pref[i] = pref[i-1] ;
   }

}

int main()
{

    SieveOfEratosthenes();
       int n ;
    cin >> n;
    while(n--)
    {
        int lf , rt ;
        cin >> lf >> rt ;
        cout << pref[rt] - pref[lf-1]  << endl;
    }



    return 0;
}
