#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define ll long long
using namespace std;
const int INF=1e9+7;
const int max_n=300001;
int bit[max_n+1];
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i -= i & -i;
	}
	return s;
}
void add(int i, int x){
	while(i<=max_n){
		bit[i]+=x;
		i += i & -i;
	}
}
int main(){
    ll n; cin>>n;
    int a[100001];
    FOR(i,0,n) cin>>a[i];
    int st=0,en=INF;
    while(st+1<en){
        int mid=(st+en)/2;
        int b[100001]={};
        b[0]=120000;
        FOR(i,0,n){
            if(a[i]>=mid) b[i+1]=b[i]+1;
            else b[i+1]=b[i]-1;
        }
        memset(bit,0,sizeof(bit));
        ll c=0;
        FOR(i,0,n+1){
            c+=sum(b[i]);
            add(b[i],1);
        }
        if(2*c>=n*(n+1)/2) st=mid;
        else en=mid;
    }
    cout<<st<<endl;
}
