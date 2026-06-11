#include<bits/stdc++.h>
using namespace std;
long long a,b,c,d,e,pas;
string s,h,j,r;
map <pair <string, string>, long long> m,n;
map <pair <string, string>, long long>::iterator it;
void rec(long long q){
	if(q>a){
		m[make_pair(h,j)]++;
		return;
	}
	r=s[q-1];
	h.insert(h.size(),r);
	rec(q+1);
	h.erase(h.size()-1,1);
	r=s[q-1];
	j.insert(j.size(),r);
	rec(q+1);
	j.erase(j.size()-1,1);
}
void rec2(long long q){
	if(q>a*2){
		pas=pas+m[make_pair(h,j)];
		return;
	}
	r=s[q-1];
	h.insert(0,r);
	rec2(q+1);
  r=s[q-1];
	h.erase(0,1);
	j.insert(0,r);
	rec2(q+1);
	j.erase(0,1);
}
int main(){
	ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>a>>s;
	rec(1);
	h.clear();
	j.clear();
	rec2(a+1);
	cout<<pas;
	return 0;
}