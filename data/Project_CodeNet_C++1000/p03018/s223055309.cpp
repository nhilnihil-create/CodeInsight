#include <iostream>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n=s.size();
	long long ans=0;
	for(int i=0;i+2<n;i++){
		if(s[i]=='A'&&s[i+1]=='B'&&s[i+2]=='C'){
			long long a=i,bc=i+1;
			while(a>=0&&s[a]=='A'){
				a--;
			}
			while(bc+1<n&&s[bc]=='B'&&s[bc+1]=='C'){
				bc+=2;
			}
			ans+=(i-a)*((bc-1)-i)/2;
			for(int j=a+1;j<a+1+((bc-1)-i);j+=2){
				s[j]='B';
				s[j+1]='C';
			}
			for(int j=a+1+((bc-1)-i);j<a+1+((bc-1)-i)+(i-a);j++){
				s[j]='A';
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}