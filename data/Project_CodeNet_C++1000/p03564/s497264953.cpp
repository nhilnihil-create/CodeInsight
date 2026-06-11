#include <bits/stdc++.h>
using namespace std;
 
int main()
{
  int l=1;
  int N;
 int K;
 cin>>N;
 cin>>K;
 for(int i=0;i<N;i++)
 {
   if(l<K)l*=2;else l+=K;
 }
 cout<<l<<endl;

}