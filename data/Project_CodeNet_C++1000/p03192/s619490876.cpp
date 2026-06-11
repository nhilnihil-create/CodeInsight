#include <bits/stdc++.h>
using namespace std;

int main()
{
     int n;
     cin>>n;
     int cp=0;
     while(n!=0){
         if(n%10==2)
         cp++;
         n/=10;
     }
     cout<<cp;
    return 0;
}
