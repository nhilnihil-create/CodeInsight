//similar means +/- 1 - product is even when atleast one number is even
//will one number be always even
//i -1 or +1 3^10 chances 
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int >nos(10,0);
int calc(int i,int even){
    //cout<<i<<' '<<even<<'\n';
	if(i==n && even==0)return 0;
    if(i==n && even==1)return 1;
    int nways=0;
    //don't change
   	if(nos[i]%2==0)nways+=calc(i+1,1);
    else nways+=calc(i+1,even);
    //make -1
   	if((nos[i]-1)%2==0)nways+=calc(i+1,1);
    else nways+=calc(i+1,even);
    //make 1
   	if((nos[i]+1)%2==0)nways+=calc(i+1,1);
    else nways+=calc(i+1,even);
    return nways;
}
int main(){
	cin>>n;
    for(int i=0;i<n;i++)cin>>nos[i];
    //calc - index,even or not
    cout<<calc(0,0);
}