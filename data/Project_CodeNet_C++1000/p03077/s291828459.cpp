#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

const long long INF = 1e17+7;
const long long MOD = 1e9+7;
const double PI=acos(-1);

using namespace std;

int main(){
	long long n;
	cin >> n;
	vector<long long> a(5),b(5,0);
	
	long long mi_num=INF;
	int mi_i;
	for(int i=0;i<5;i++){
		cin >> a[i];
		if(mi_num>a[i]){
			mi_num=a[i];
			mi_i=i;
		}
	}
	
	long long ans=0;
	long long m=n;
	for(int i=4;i>=0;i--){
		b[i]=min(m,mi_num);
		m-=b[i];
		if(m<0)m=0;
	}
	ans+=5;
	ans+=(m+(mi_num-1))/mi_num;
	
	int temp=0;
	for(int i=0;i<5;i++){
		if(b[i]==0)temp++;
	}
	temp=4-temp;
	ans+=temp;

	cout << ans << endl;
	return 0;
}
