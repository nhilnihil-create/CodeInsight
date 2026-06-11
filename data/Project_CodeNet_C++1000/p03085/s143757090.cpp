#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using ll=long long;
using namespace std;
const long MOD=1e9+7;
template<class T>
T lcm(T a,T b){
    return a/__gcd(a,b)*b;
}

int main(){
    char c;cin >> c;
  	map<char,char> m;
  	m['A']='T';
  	m['T']='A';
  	m['C']='G';
  	m['G']='C';
  	cout << m[c];
    return 0;
}