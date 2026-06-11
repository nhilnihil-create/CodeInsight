#include<iostream>
#include<string>
#include<algorithm>
#define INF 0x3f3f3f3f
std::string s;
int len;
int ans=INF;
int main(){
	std::cin>>s;
	len=s.size();
	for(int i=0;i<len;i++){
		if(s[i]!=s[i-1]) ans=std::min(ans,std::max(i,len-i));
	}
	ans=std::min(ans,len);
	printf("%d\n",ans);
	return 0;
}