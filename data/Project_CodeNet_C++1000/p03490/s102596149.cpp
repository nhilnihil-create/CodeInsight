#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
bool a[8011];
bool b[8011];
bool check(vector<int>v,int x){
	if(x<0||x>8001)return false;
	REP(i,8001)a[i]=false;
	a[0]=true;
	REP(i,v.size()){
		REP(j,8001){
			b[j]=a[j];
		}
		REP(j,8001){
			if(a[j]==true&&(j+v[i]<8001)){
				b[j+v[i]]=true;
			}
		}
		REP(j,8001){
			a[j]=b[j];
		}
	}
	//cout<<x<<" "<<a[x]<<endl;
	if(a[x]==true)return true;
	return false;
}
int main(){
	string s;
	int x,y;
	cin>>s>>x>>y;
	int count=0;
	int now=0;
	while(now<s.size()&&s[now]=='F'){
		now++;
		count++;
	}
	x-=count;
	x=abs(x);
	y=abs(y);
	vector<int>v;
	vector<int>vv;
	int me=0;
	count=0;
	for(int i=now;i<s.size();i++){
		if(s[i]=='F'){
			count++;
		}else{
			if(me==0){
				v.push_back(count);
			}else{
				vv.push_back(count);
			}
			count=0;
			me=1-me;
		}
	}
	if(me==0){
		v.push_back(count);
	}else{
		vv.push_back(count);
	}
	int sum=0;
	REP(i,v.size()){
		sum+=v[i];
	}
	int sum2=0;
	REP(i,vv.size()){
		sum2+=vv[i];
	}
	
	
	//cout<<sum<<" "<<sum2<<endl;
	if(check(v,(sum-x)/2)&&check(vv,(sum2-y)/2)&&((sum-x)%2==0)&&((sum2-y)%2==0)){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	
	return(0);
}