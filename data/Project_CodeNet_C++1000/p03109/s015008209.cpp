/****************************************************************************************************
                                        SUBMITTED BY-

                                            AISH_07

****************************************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define vi vector<int>
#define ll long long
#define sl set<ll>
#define vs vector<string>
#define pb push_back
#define vl vector<ll>
#define vi vector<int>
#define PI  3.14159265
#define mod 998244353
int main()
{
   string s;
   cin>>s;

   string q=s.substr(0,4);
   string d=s.substr(5,2);
   string n=s.substr(8,2);


   int y=stoi(q);
   int mm=stoi(d);
   int dd=stoi(n);

   if(y>2019)
      cout<<"TBD\n";
   else
   {
       if(mm>4)
        cout<<"TBD\n";
       else
         cout<<"Heisei\n";
   }
   return 0;
}
