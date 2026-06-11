#include<bits/stdc++.h>
#define fastio 	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define unmap  	unordered_map<int,int>
#define	unset	unordered_set<int>
#define maxpq  	priority_queue<int>
#define minpq  	priority_queue<int, vector<int>, greater<int>>
#define pb 		push_back		
#define ll 		long long
#define ull     unsigned ll
#define ff 		first
#define ss 		second//typedef second ss;
#define foton(i,n) for(int i=0;i<n;i++)
#define	faton(i,a,n)	for(int i=a;i<=n;i++)
#define mod 	1000000007
#define endl "\n"
using namespace std;

int n,m;
char a[1001][1001];
int t[1001][1001];
int add(int a, int b){
    return ((a%mod)+(b%mod))%mod;
}
int fun(int i,int j){
    if(a[i][j] == '#') return 0;
    if(i>=n || j>=m) return 0;
    if(i==n-1 && j==m-1) return 1;
    if(t[i][j] != -1) return t[i][j];
    return t[i][j] = add(fun(i+1,j),fun(i,j+1));
}
int main(){
    cin>>n>>m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    memset(t,-1,sizeof(t));
    cout<<fun(0,0)%mod<<endl;
}
