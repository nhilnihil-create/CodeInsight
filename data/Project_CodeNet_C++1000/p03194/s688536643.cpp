
#include<bits/stdc++.h>
using namespace std;
int main()
{

    long long int n,m;
  while(cin>>n>>m){
    long long int ans = 1;
    if(n==1 || m==1) {cout<<m<<endl; continue;}
    long long int maxx = sqrt(m);
    maxx+=2;
    for (long long int i=2;i<=maxx;i++){
        long long int c=0;
        while(m%i==0){
            m=m/i;
            c++;
            if(c==n)
            {ans = ans*i;c=0;}
        }


    }
    cout<<ans<<endl;
  }
}
