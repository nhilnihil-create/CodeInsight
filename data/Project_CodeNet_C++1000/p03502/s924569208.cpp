#include<bits/stdc++.h>
using namespace std;
int main(){
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
   	#endif
    int n;
    cin>>n;
    int temp=n;
    int sum=0;
    while(temp>0){
    	sum+=temp%10;
    	temp/=10;
    }
    cout<<((n%sum==0)?"Yes":"No");
   return 0;
}