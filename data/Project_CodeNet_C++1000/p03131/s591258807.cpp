#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
  ll chances,val1,val2;
  cin>>chances>>val1>>val2;
  ll answer=val1;
  if(val2-val1<=2){
    cout<<chances+1;
    return 0;
  }
  chances=chances-(val1-1);
  if(chances%2==0)
  {
    answer+=(chances/2)*(val2-val1);
  }
  else
  {
    answer+=(chances/2)*(val2-val1)+1;
  }
  cout << answer;
}