#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <int,int> pa;
const int N = 2e5+100;

int n;
int a[N];
void solve()
{
   cin>>n;
   int z=0,pos=1;
   for(int i=1;i<=n;i++) {
    cin>>a[i];
    if(abs(a[i])>abs(z)) z=a[i],pos=i;
   }
   if(z<0) {
      cout<<2*n<<endl;
      cout<<pos<<" "<<1<<endl;
      cout<<pos<<" "<<1<<endl;
      for(int i=n;i>=2;i--) {
         cout<<1<<" "<<i<<endl;
         cout<<1<<" "<<1<<endl;
      }
   }
   else if(z>0) {
     cout<<2*n<<endl;
     cout<<pos<<" "<<n<<endl;
     cout<<pos<<" "<<n<<endl;
     for(int i=1;i<n;i++) {
        cout<<n<<" "<<i<<endl;
        cout<<n<<" "<<n<<endl;
     }
   }
   else cout<<0<<endl;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
