        #include <bits/stdc++.h>
        using namespace std;
        #define int long long

        signed main() {
            int n;
            cin>>n;
            int a[n];
            for(int i=0;i<n;i++)cin>>a[i];
            sort(a,a+n);
            int ans=a[0];
            for(int i=1;i<n-1;i++){
                if(abs(a[n-1]-2*ans)>abs(a[n-1]-2*a[i]))ans=a[i];
            }
            cout<<a[n-1]<<' '<<ans;

         return 0;

        }
