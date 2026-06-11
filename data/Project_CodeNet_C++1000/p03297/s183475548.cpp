#include<bits/stdc++.h>
using namespace std;
namespace whatever{
	int readu(){
		char ch=getchar();
		while(!isdigit(ch))
			ch=getchar();
		int value=ch-'0';
		ch=getchar();
		while(isdigit(ch)){
			value=value*10+ch-'0';
			ch=getchar();
		}
		return value;
	}
	long long readull(){
		char ch=getchar();
		while(!isdigit(ch))
			ch=getchar();
		long long value=ch-'0';
		ch=getchar();
		while(isdigit(ch)){
			value=value*10+ch-'0';
			ch=getchar();
		}
		return value;
	}
	long long gcd(long long a, long long b){
		return b==0? a: gcd(b, a%b);
	}
	void run(){
		int t=readu();
		while(--t!=-1){
			long long a=readull();
			long long b=readull();
			long long c=readull();
			long long d=readull();
			bool result;
			int type;
			if(d<b||a<b||c<a%b){
				result=false;
				type=0;
			}
			else if(d==b){
				result=true;
				type=1;
			}
			else{
				long long g=gcd(b, d);
				a%=g;
				long long min_value=(c-a+g)/g*g+a-b;
				result=(min_value>=0);
				type=2;
			}
			puts(result?"Yes":"No");
			cerr<<"type: "<<type<<endl;
		}
	}
}
int main(){
	whatever::run();
}