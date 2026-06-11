#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair <int,int> pa;
const int N = 2e5+100;

int n,h;
int a[N],b[N];
void solve()
{
   cin>>n>>h;
   for(int i=1;i<=n;i++) {
    cin>>a[i]>>b[i];
   }
   sort(a+1,a+1+n,greater<int>());
   sort(b+1,b+1+n,greater<int>());
   int kk=a[1];
   int ans=0;
   int pos=1;
   while(1){
     if(h<=0) {
        cout<<ans<<endl;
        return ;
     }
     if(b[pos]>kk) {
        h-=b[pos++];
        ans++;
     }
     else break;
   }
   ans+=h/kk;
   if(h%kk) ans++;
   cout<<ans<<endl;

}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
