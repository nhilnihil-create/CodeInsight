#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n,val;
    cin>>val;
    n=val;
    int sum=0;
    while(n!=0){
        sum+=(n%10);
        n=n/10;
    }
   if(val%sum==0)
        cout<<"Yes";
    else cout<<"No";
  return 0;
}
