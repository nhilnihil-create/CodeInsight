#include<bits/stdc++.h>
using namespace std ;

// #define int long long
#define endl '\n'
string make(string s,int k)
{
	string ans="";
	for(int i=0;i<k;i++)
		ans+=s;
	return ans;
}

int32_t main()
{

   string s;
   cin>>s;
   int n=s.size();
   if(n==1){
   	cout<<'0';return 0;
   }
   string f,se;
   if(n&1){
   	f=make("01",n/2)+"0";
	se=make("10",n/2)+"1";
   }
   else{
   	f=make("01",n/2);
   	se=make("10",n/2);
   }
   int cnt1=0,cnt2=0;
   // cout<<se<<" "<<f;
   for(int i=0;i<n;i++)
   {
   	if(s[i]!=f[i])
   		cnt1++;
   	else
   		cnt2++;
   }
   cout<<min(cnt1,cnt2);
   	return 0;
}
