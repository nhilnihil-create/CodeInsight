#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<map>
#include<tuple>
#define rep(index,num) for(int index=0;index<num;index++)
#define rep1(index,num) for(int index=1;index<=num;index++)
#define scan(argument) cin>>argument
#define prin(argument) cout<<argument<<endl
#define kaigyo cout<<endl
#define eps 1e-15
#define mp(a1,a2) make_pair(a1,a2)
typedef long long ll;
using namespace std;
typedef pair<ll,ll> pll;
typedef pair<int,int> pint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<pint> vpint;
typedef vector<pll> vpll;
ll INFl=1e+18+1;
int INF=1e+9+1;
ll N;
int a[100001];
int asort[100001];
ll Merge(std::vector<ll>& a, ll i, ll chunk_size, std::vector<ll>& tmp) {
     std::vector<ll>::iterator a1 = a.begin() + i;
     ll l1 = chunk_size;
     std::vector<ll>::iterator a2 = a1 + l1;
     ll l2 = (a.size() > i + chunk_size * 2) ? chunk_size : a.size() - i - chunk_size;

     tmp.clear();
     ll res = 0;

     for (ll i1 = 0, i2 = 0; i1 != l1 || i2 != l2; ) {
          if (i1 == l1) {
               tmp.push_back(a2[i2++]);
          } else if (i2 == l2) {
               tmp.push_back(a1[i1++]);
          } else if (a1[i1] < a2[i2]) {
               tmp.push_back(a1[i1++]);
          } else if (a2[i2] < a1[i1]) {
               tmp.push_back(a2[i2++]);
               res += l1 - i1;
          } else {
               std::cerr << "Oops" << std::endl;
          }
     }

     for (ll di = 0; di < tmp.size(); ++di)
          a[i + di] = tmp[di];

     return res;
}

ll CountCross(std::vector<ll>& a) {
     ll res = 0;
     std::vector<ll> tmp(a.size());

     for (ll chunk_size = 1; chunk_size < a.size(); chunk_size *= 2)
          for (ll i = 0; i + chunk_size < a.size(); i += chunk_size * 2)
               res += Merge(a, i, chunk_size, tmp);

     return res;
}
int tyuou(int ximin,int ximax){
	int endflag=0;
	if(ximin+1>=ximax) endflag=1;
	int ximid=(ximin+ximax)/2+(ximin+ximax)%2;
	int x=asort[ximid];
	vll S;
	S.push_back(0);
	rep(i,N){
		if(a[i]<x){
			S.push_back(S.back()-1);
		}
		else{
			S.push_back(S.back()+1);
		}
	}
	rep(i,N+1){
		S[i]=S[i]*1e+9+i;
	}
	ll zeroijo=N*(N+1)/2-CountCross(S);
	//printf("min:%d max:%d mid:%d zeroijo:%lld\n",ximin,ximax,ximid,zeroijo);
	if(zeroijo>=N*(N+1)/2/2+N*(N+1)/2%2){
		if(endflag) return x;
		else return tyuou(ximid,ximax);
	}
	else{
		if(endflag) return asort[ximid-1];
		return tyuou(ximin,ximid);
	}
}
int main(){
	scan(N);
	rep(i,N){
		scan(a[i]);
		asort[i]=a[i];
	}
	sort(asort,asort+N);
	prin(tyuou(0,N-1));
	return 0;
}
