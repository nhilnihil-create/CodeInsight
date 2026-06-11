#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)
#define sz(c) ((int)(c).size())

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
//const int MAX=;



int main(){
	ll N,A,B;
	cin>>N>>A>>B;
	
	if(B==1){
		if(N==A){
			rep1(i,N)cout<<i<<" ";
		}
		else cout<<-1<<endl;
		return 0;
	}
	if(A==1){
		if(N==B){
			for(int i=N; i>=1; i--)cout<<i<<" ";
		}
		else cout<<-1<<endl;
		return 0;
	}
	
	if(A+B-1<=N && N<= A*B){
		for(int i=N-A+1;i<=N;i++)cout<<i<<" ";
		int k=N-A;
		if(k%(B-1)==0){
			int q=k/(B-1);
			for(int j=(B-2)*q+1;j>0;j-=q){
				for(int g=j;g<j+q;g++){
					cout<<g<<" ";
				}
			}
		}
		else{
			int q=k/(B-1);
			int r=k%(B-1);
			vector<int> v;
			int p=0;
			v.push_back(p);
			rep1(j,B-1){
				if(j<=B-1-r)p+=q;
				else p+=q+1;
				v.push_back(p);
			}
			for(int j=B-1; j>=1; j--){
				for(int g=v[j-1]+1; g<=v[j]; g++)cout<<g<<" ";
			}
		}
		cout<<endl;
	}
	else{
		cout<<-1<<endl;
	}
}