#include<bits/stdc++.h>

#define faster     ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
#define read       freopen("input.txt", "r", stdin);
#define write      freopen("output.txt", "w", stdout);
#define endd        '\n'
#define ll         long long
#define sq(a)      ((a) * (a))

using namespace std;
int main()
{
      faster;
      double pi = 2 * acos(0.0);
      ll int n,i,t,j,k,m=0,b,c,d,p,q,r,x=250,y=10,z,count=0;
      cin>>n;
      ll int ara1[n],ara2[n],ara3[n],ara4[n];
      for(i=0;i<n;i++){
            cin>>ara1[i];
      }
      for(i=0;i<n;i++){
            cin>>ara2[i];
            m=ara1[i]-ara2[i];
            if(m>=0)count+=m;
      }
      cout<<count;
      return 0;
}
//Sheikh Tafsir Rahman
//CSE IUT