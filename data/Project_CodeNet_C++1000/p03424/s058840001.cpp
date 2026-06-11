#include <bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin>> N;
  string S;
  int a=0,b=0,c=0,d=0;
  for( int i=0;i<N;i++)
  {
    cin>>S;
    
  	if(S == "P")
    { a=1;
    }
    if(S == "W")
    { b=1;
    }
    if(S == "G")
    { c=1;
    }
    if(S == "Y")
    { d=1;
    }
  }
  if( a == b && b== c && c == d)
    {cout<< "Four" <<endl;}
  else
  {cout<< "Three"<<endl;}
}
