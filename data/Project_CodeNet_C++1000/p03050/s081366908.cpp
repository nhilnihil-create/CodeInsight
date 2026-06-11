#include<iostream>
using namespace std;
#include<vector>
#include<set>
#define int long long int
int32_t main()
{
     int n;
     cin>>n;
     //int answer=0;
     set<int> s;
     for(int i=1;i*i<=n;i++)
     {
		 if(n%i==0)
		 {
              int f1=i;
              int f2=n/i;
              int factor=f2-1;
              if(factor!=0&&n/factor==n%factor)
              {
				  s.insert(factor);
			  }
              factor=f1-1;
              if(factor!=0&&n/factor==n%factor)
              {
				  s.insert(factor);
			  }
		 }
	 }
	 int sum=0;
	 for(int x:s)
	    sum+=x;
	 cout<<sum<<endl;
}
