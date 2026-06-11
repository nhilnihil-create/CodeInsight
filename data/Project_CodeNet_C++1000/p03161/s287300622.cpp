#include<bits/stdc++.h>
using namespace std;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);cout.tie(NULL);
        long long int n,i,k;
        cin>>n>>k;
        vector<long long int> h(n);
        for(i=0;i<n;i++){
                cin>>h[i];
        }
        vector<long long int> cost(n);
        cost[n-1]=0;
        cost[n-2]=abs(h[n-1]-h[n-2]);
        for(i=n-3;i>=0;i--){
                long long int j,temp,min;
                min=cost[i+1]+abs(h[i+1]-h[i]);
                for(j=i+1;j<=i+k && j<n;j++){
                        temp=cost[j]+abs(h[j]-h[i]);
                        if(temp<min){
                                min=temp;
                        }
                }
                cost[i]=min;
      
        }
        cout<<cost[0];
        
return 0;
}
/*

        creation time:  16.09.2020 10:56:33

*/                      

