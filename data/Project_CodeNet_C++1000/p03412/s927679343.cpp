        #include <bits/stdc++.h>
        using namespace std;
        #define int long long

        signed main() {
        int n;
        cin>>n;
       int a[n],b[n],x[n],y[n],ans=0,k;
       if(n%2){
       for(int i=0;i<n;i++){cin>>a[i];ans=ans^a[i];}
       for(int i=0;i<n;i++){cin>>b[i];ans=ans^b[i];}
       }
       else{
           for(int i=0;i<n;i++)cin>>a[i];
           for(int i=0;i<n;i++)cin>>b[i];
       }
         //cerr<<ans;
        for(int i=1;i<=28;i++){
            for(int j=0;j<n;j++)x[j]= a[j]-((a[j]>>(i))<<(i));
            for(int j=0;j<n;j++)y[j]= b[j]-((b[j]>>(i))<<(i));
            sort(x,x+n);sort(y,y+n);
            k=n-1;
            for(int j=0;j<n;j++){
                while(k>=0&&y[k]+x[j]>=(1ll<<(i)))k--;
                ans=ans^((1ll<<i)*((n-1-k)%2));
            }
           // cerr<<ans;

        }
        cout<<ans;


        }
