#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;cin>>n;
  vector<int >t(n,0),x(n,0),y(n,0);
  for(int i=0;i<n;i++)cin>>t[i]>>x[i]>>y[i];
  int startx=0,starty=0;
  int pos=1;
  int dist;
  int times;
  for(int i=0;i<n;i++){
    //  cout<<startx<<' '<<starty<<'\n';
        if(i!=0)times=t[i]-t[i-1];
        else times=t[i];
		dist = abs(x[i]-startx)+abs(y[i]-starty);
    	if(dist<=times && times%2==dist%2){startx=x[i];starty=y[i];continue;}
    	else {pos=0;break;}
  }
  if(pos==0)cout<<"No";
  else cout<<"Yes";
}