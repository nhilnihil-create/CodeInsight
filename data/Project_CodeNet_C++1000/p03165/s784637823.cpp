#include <bits/stdc++.h>
#include <iostream>

#define boost ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll long long int
#define lld long double
#define f(i,a,b) for(int i=a;i<b;i++)
#define mod 1000000007
#define pb push_back
#define mp make_pair
#define pii pair<long long, long long >
#define INF 10000000000000009 //1e16+9
#define F first
#define S second
//#define MAX
using namespace std;
stack<char>s1;

void solve()
{ string s,t;
cin>>s>>t;
int i,j,arr[s.size()+1][t.size()+1];
for(i=0;i<=s.size();i++)
    for(j=0;j<=t.size();j++)
  {
    if(i==0 || j==0)
        arr[i][j]=0;
    else {
        if(s[i-1]==t[j-1])
            arr[i][j]=arr[i-1][j-1]+1;
        else arr[i][j]=max(arr[i-1][j],arr[i][j-1]);
      }
   }
   i=s.size(),j=t.size();

while(i!=0 && j!=0){
if(s[i-1]==t[j-1])
    {s1.push(s[i-1]);
    i--;j--;}
    else{
        if(arr[i-1][j]<arr[i][j-1])
             j--;
        else
             i--;

         }

}

while (!s1.empty())
    {
        cout << s1.top();
        s1.pop();
    }

    }

int main()
{
	boost;
	//int t;
	//cin>>t;
	//while(t--)
	//{

		solve();
		//cout<<endl;
	//}
	return 0;
}
