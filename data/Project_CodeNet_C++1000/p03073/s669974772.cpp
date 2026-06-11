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
      ll int n,i,t,j,k,m=0,a=0,b=0,c=0,d=0,p,q,r,x=250,y=10,z,count=0;
      string str;
      cin>>str;
      n=str.size();
      for(i=0;i<n;i++){
            if(i%2==0 && str[i]=='1')a++;
            else  if(i%2==1 && str[i]=='0')a++;
            else if(i%2==0 && str[i]=='0')b++;
            else  if(i%2==1 && str[i]=='1')b++;
      }
      cout<<n-max(a,b);
      return 0;
}
//Sheikh Tafsir Rahman
//CSE IUT