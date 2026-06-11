#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 1000000007
typedef long long ll;
using namespace std;
#define N 100010
int n,a[N],b[N];
int main(){
    cin>>n;
    lol(i,n)cin>>a[i]>>b[i];
    a[n]=b[n]=0;
    n++;
    sort(a,a+n,greater<int>());
    sort(b,b+n);
    ll ans=0;
    lol(i,n){
	ans+=max(0,a[i]-b[i]);
    }
    cout<<ans*2<<endl;
    return 0;
}
