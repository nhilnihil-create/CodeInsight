#include <bits/stdc++.h>
#define FLASH ios_base::sync_with_stdio(0);
#define ll long long
#define debt(x,y)cout<<"#x = "<<(x)<<" and "<<"#y = "<<(y)<<endl;
#define deb(x)cout<<"#x = "<<(x)<<endl;
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define arr(a,n) for(ll i=1;i<=n;i++) cout<<a[i]<<" "; cout << "\n";
#define vecc(a,n) for(ll i=0;i<n;i++) cout<<a[i]<<" "; cout << "\n";


using namespace std;

ll a,b,k;

int main(){
FLASH;
cin>>a>>b>>k;
ll raz=b-a+1;
if(raz<=k)
{
  for(ll i=a;i<=b;i++)cout<<i<<endl;	
}
else
{
  set<ll>el;
  for(ll i=a;i<a+k;i++)el.insert(i);
  for(ll i=b;i>=b-k+1;i--)el.insert(i);
  for(auto i:el)cout<<i<<endl;	
}







return 0;
} 
