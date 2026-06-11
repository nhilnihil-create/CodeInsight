#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

bool do_dp(vector<int> v,int sum){
	vector<bool> dp;
	dp.assign(8080,false);
	dp[0] = true;
	if(sum<0) return false;
	for(int i=0;i<v.size();i++){
		for(int j=8080;j>=0;j--){
			if(j-v[i]>=0&&dp[j-v[i]]) dp[j] = true;
		}
	}
	if(dp[sum]) return true;
	else return false;
}

int main(){
	char s[8080];
	int x,y;
	int cnt = 0;
	bool tate_desu = false;
	vector<int> tate,yoko;
	scanf("%s%d%d",s,&x,&y);
	for(int i=0;s[i]!='\0';i++){
		if(s[i]=='T'){
			if(tate_desu){
				tate_desu = false;
				tate.push_back(cnt);
			}else{
				tate_desu = true;
				yoko.push_back(cnt);
			}
			cnt = 0;
		}else{
			cnt++;
		}
	}
	if(tate_desu) tate.push_back(cnt);
	else yoko.push_back(cnt);
	int tate_total = 0;
	int yoko_total = 0;
	for(int i=0;i<tate.size();i++) tate_total += tate[i];
	for(int i=0;i<yoko.size();i++) yoko_total += yoko[i];
	int ue_sum = (tate_total + y) / 2;
	int migi_sum = (yoko_total + x) / 2 - yoko[0];
	reverse(yoko.begin(),yoko.end());
	yoko.pop_back();
	if((tate_total+y)%2!=0||(yoko_total+x)%2!=0) printf("No\n");
	else if(do_dp(tate,ue_sum)&&do_dp(yoko,migi_sum)) printf("Yes\n");
	else printf("No\n");
}
