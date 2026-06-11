#include<bits/stdc++.h>
using namespace std;
int cnt[5];
int main(){
	int a,b;
  	for(int i=1;i<=3;i++){
    	cin>>a>>b;cnt[a]++;cnt[b]++;
    }
  	if(count(cnt+1,cnt+5,2)==2) cout<<"YES";
  	else cout<<"NO";
}