#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define Inf 1000000000

struct Bitset{
	using ull =  __uint128_t;//unsigned long long;
	vector<ull> b;
	int n;
	Bitset(int x){
		n = x;
		b.resize((n+127)/128,0);
	}
	
	int get(int x){
		return (b[x>>7]>>(x&127))&1;
	}
	
	void set(int x,int y){
		b[x>>7] |= 1ULL<<(x&127);
		if(!y)b[x>>7] ^= 1ULL<<(x&127);
	}
	
	Bitset &operator&=(const Bitset &another){
		rep(i,b.size()){
			b[i] &= another.b[i];
		}
		return (*this);
	}
	
	Bitset operator&(const Bitset &another)const{
		return (Bitset(*this)&=another);
	}
	
	Bitset &operator|=(const Bitset &another){
		rep(i,b.size()){
			b[i] |= another.b[i];
		}
		return (*this);
	}
	
	Bitset operator|(const Bitset &another)const{
		return (Bitset(*this)|=another);
	}
	
	Bitset &operator^=(const Bitset &another){
		rep(i,b.size()){
			b[i] ^= another.b[i];
		}
		return (*this);
	}
	
	Bitset operator^(const Bitset &another)const{
		return (Bitset(*this)^=another);
	}
	
	Bitset &operator>>=(int x){
		if(x&63){
			rep(i,b.size()-1){
				b[i] >>= (x&63);
				b[i] ^= (b[i+1]<<(64-(x&63)));
			}
			b.back() >>= (x&63);
		}
		
		x>>=6;
		rep(i,b.size()){
			if(i+x<b.size())b[i] = b[i+x];
			else b[i]=0;
		}
		return (*this);
	}
	
	Bitset operator>>(int x)const{
		return (Bitset(*this)>>=x);
	}
	
	Bitset &operator<<=(int x){
		if(x&127){
			for(int i=b.size()-1;i>=1;i--){
				b[i] <<= (x&127);
				b[i] ^= b[i-1]>>(128-(x&127));
			}
			b[0] <<= x&127;
		}
		
		x>>=7;
		for(int i=b.size()-1;i>=0;i--){
			if(i-x>=0)b[i] = b[i-x];
			else b[i] = 0;
		}
		return (*this);
	}
	
	Bitset operator<<(int x)const{
		return (Bitset(*this)<<=x);
	}
	
};

int main(){
	
	int N;
	cin>>N;
	
	vector<int> A(N);
	int S = 0;
	
	for(int i=0;i<N;i++){
		cin>>A[i];
		S += A[i];
	}
	
	
	Bitset B(4000001);
	B.set(0,1);
	
	for(int i=0;i<N;i++){
		B |= (B<<A[i]);
	}
	
	int k = (S+1)/2;
	
	for(int i=k;true;k++){
		if(B.get(k)){
			cout<<k<<endl;
			return 0;
		}
	}
 
	
	return 0;
}
 
