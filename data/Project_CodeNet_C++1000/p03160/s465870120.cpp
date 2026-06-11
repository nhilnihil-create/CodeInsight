#include<bits/stdc++.h>
using namespace std;
int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);cout.tie(NULL);
        long int n;
        cin>>n;
        vector<long int> h(n),cost(n,0);
        for(long int i=0;i<n;i++){
                cin>>h[i];
        }
        cost[n-1]=0;
        cost[n-2]=abs(h[n-1]-h[n-2]);
        for(long int i=n-3;i>=0;i--){
                long int a,b;
                a=cost[i+1]+abs(h[i+1]-h[i]);
                b=cost[i+2]+abs(h[i+2]-h[i]);
                cost[i]=min(a,b);}
                cout<<cost[0];
        
return 0;
}
/*

        creation time:  15.09.2020 20:19:41

*/                      

