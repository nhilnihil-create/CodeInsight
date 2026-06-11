#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <stdio.h> 
using namespace std;
	typedef long long int lli;
	const int MaxN=200005;
	#define fst first
	#define snd second
	#define mp make_pair
	lli mcd(lli a,lli b){	
		if(a==0)return b;
		return mcd(b%a,a);
	}		
	set <string> res;
int main(){
	lli t,N,Q,i,j,p,q,c=0;
	string word;
	string aux;
	cin>>word;
	N=word.size();
	cin>>Q;
	for(i=0;i<N;i++){
		aux=word[i];
		res.insert(aux);
		for(j=i+1;j<min(lli(N),i+50);j++){
			aux.push_back(word[j]);
			res.insert(aux);
		}
	}
	set <string>::iterator it;
	for(it=res.begin();it!=res.end();it++){
		c+=1;
		if(c==Q){
			cout<<*it;
		}
	}
}