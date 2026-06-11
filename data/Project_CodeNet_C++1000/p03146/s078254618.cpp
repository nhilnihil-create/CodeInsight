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
    int s;
    cin>>s;

    int i,prev=s;
    set<int>se;
    se.insert(s);
    for( i=2;i<=1000000;i++)
    {
        if(prev%2==0)
        {

            if(!binary_search(se.begin(),se.end(),prev/2))
            {
                se.insert(prev/2);
                prev/=2;
            }
            else
              break;
        }
        else
        {

            if(!binary_search(se.begin(),se.end(),3*prev+1))
            {
                se.insert(3*prev+1);
                prev=3*prev+1;
            }
            else
              break;
        }
    }
    cout<<i<<"\n";
    return 0;
}
