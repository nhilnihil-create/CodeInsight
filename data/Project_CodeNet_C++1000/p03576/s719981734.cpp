#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    long long int x[n],y[n];
    for(int i=0;i<n;i++)cin >> x[i] >> y[i];
    long long int ans=5e18;
    if(k==2){
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ans=min(ans,abs(x[i]-x[j])*abs(y[i]-y[j]));
            }
        }
        cout << ans;
    }
    else if(k==3){
        for(int i=0;i<n-2;i++){
            for(int j=i+1;j<n-1;j++){
                for(int l=j+1;l<n;l++){
                    long long int MAX=max(x[i],max(x[j],x[l]));
                    long long int MAY=max(y[i],max(y[j],y[l]));
                    long long int MIX=min(x[i],min(x[j],x[l]));
                    long long int MIY=min(y[i],min(y[j],y[l]));
                    ans=min(ans,(MAX-MIX)*(MAY-MIY));                    
                }
            }
        }
        cout << ans;
    }
    else{
        for(int i=0;i<n-3;i++){
            for(int j=i+1;j<n-2;j++){
                for(int l=j+1;l<n-1;l++){
                    for(int m=l+1;m<n;m++){
                        long long int MAX=max(max(x[i],x[m]),max(x[j],x[l]));
                        long long int MAY=max(max(y[i],y[m]),max(y[j],y[l]));
                        long long int MIX=min(min(x[i],x[m]),min(x[j],x[l]));
                        long long int MIY=min(min(y[i],y[m]),min(y[j],y[l]));
                        int count=0;
                        for(int a=0;a<n;a++)if(x[a]<=MAX && x[a]>=MIX && y[a]<=MAY && y[a]>=MIY)count++;
                        if(count>=k)ans=min(ans,(MAX-MIX)*(MAY-MIY));
                    }
                }
            }
        }
        cout << ans;
    }    
}