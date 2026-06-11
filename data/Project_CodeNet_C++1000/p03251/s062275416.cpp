        #include <bits/stdc++.h>
        using namespace std;
   #define int long long
   #define PP pair<int,pair<int,int>>
const int MAX = 1000001;
const int MOD =1000000007;
const int INV2 = (MOD+1)/2;



     signed main(){
 int n,m,x,y;
 cin>>n>>m>>x>>y;
 int a[n],b[m];
 for(int i=0;i<n;i++)cin>>a[i];
 for(int i=0;i<m;i++)cin>>b[i];
 sort(a,a+n);sort(b,b+m);
 if(a[n-1]<b[0]&&x<b[0]&&a[n-1]<y)cout<<"No War";
 else cout<<"War";



}


        
