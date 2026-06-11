#include<bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)
typedef long long LL;
int N;

bool check(string A){
	int a[26];
	REP(i,26){
		a[i]=0;
	}
	REP(i,A.size()){
		a[A[i]-'a']++;
		if(a[A[i]-'a']>=2)return false;
	}
	return true;
}

int main(){
	string S;
	cin>>S;
	if(S.size()==26){
		string A=S;
		bool check=false;
		int now=-1;
		int c=-1;
		for(int i=S.size()-1;i>=0;i--){
			for(int j=i+1;j<S.size();j++){
				if(A[i]<A[j]){
					c=i;
					check=true;
					if(now==-1){
						now=j;
					}else{
						if(A[j]<A[now]){
							now=j;
						}
					}
				}
			}
			if(check==true){
				break;
			}
		}
		if(check==false){
			cout<<-1<<endl;
		}else{
			REP(i,c){
				cout<<S[i];
			}
			cout<<S[now]<<endl;
		}
	}else{
		REP(i,26){
			string A=S;
			A.push_back('a'+i);
			//cout<<A<<endl;
			if(check(A)==true){
				cout<<A<<endl;
				break;
			}
		}
	}
	return 0;
}