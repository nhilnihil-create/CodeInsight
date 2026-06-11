/// @author MuSTAFA MOGHAZY
#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool a [100+5];
int main()
{
  int a, b;
  cin>>a>>b;
  if( ((a%10) * (b%10)) % 2 == 0 ){
    cout<<"Even";
  }
  else
    cout<<"Odd";
}


