//* AuThOr GaRyMr *//
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define niv vector<int>
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define ff fflush(stdout)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
vector<int> V;
int main(){
	LL sum=0,tot,n;
	cin>>n;
	tot=n;
	if(n==3){
		cout<<"2 5 63"<<endl;;
		return 0;
	}
	rb(i,1,30000){
		if(i%2==0||i%3==0){
			tot--;
			
			sum+=i;
			V.PB(i);
			if(!tot) break;
		}
	}
//	cout<<sum<<" "<<V[n-1]<<endl;
	if(sum%6==1){
		if(V[n-1]%2==0)V[n-1]+=6;
		int OK1=0,OK2=0;
		rl(i,n-1,0){
			if(!OK1&&V[i]%2==0){
				OK1=1;
				V[i]+=2; 
			}
			else
			if(!OK2&&V[i]%3==0){
				OK2=1;
				V[i]+=3;
			}
		}
	}
	else
	if(sum%6==2){
		rl(i,n-1,0){
			if(V[i]%2==0){
				V[i]+=4;
				break;
			}
		}
	}
	else
	if(sum%6==3){
		rl(i,n-1,0){
			if(V[i]%3==0){
				V[i]+=3;
				break;
			}
		}
	}
	else 
	if(sum%6==4){
		rl(i,n-1,0){
			if(V[i]%2==0){
				V[i]+=2;
				break;
			}
		}
	}
	else
	if(sum%6==5){
		if(V[n-1]%3==0)V[n-1]+=6;
		int OK1=0,OK2=0;
		rl(i,n-1,0){
			if(!OK1&&V[i]%2==0){
				OK1=1;
				V[i]+=4; 
			}
			else
			if(!OK2&&V[i]%3==0){
				OK2=1;
				V[i]+=3;
			}
		}
	}
	rb(i,1,n) cout<<V[i-1]<<" ";
	return 0;
}
