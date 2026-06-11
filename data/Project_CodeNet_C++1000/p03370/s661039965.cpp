#include <bits/stdc++.h>
using namespace std;
int main() {
   long n,x,sum=0;
   cin>>n>>x;
   vector<long> v(n);
   for(long i=0;i<n;i++)
   {
    cin>>v[i];   
   }
   sort(v.begin(),v.end());
   for(long i=0;i<n;i++)
   {
    sum+=v[i];   
   }
   
   long p=(x-sum)/v[0];
   cout<<p+n<<"\n";
	return 0;
}
