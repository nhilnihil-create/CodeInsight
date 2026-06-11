#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define INF 1000000007
//0=48,A=65,a=97

int main() {
    int n,k;cin >> n >> k;
    vector<int> a(n);for(int i=0;i<n;i++) cin >> a[i];
    
    int z=lower_bound(a.begin(),a.end(),0)-a.begin();//zero_indexed
    int plus=min(k,n-z);//まず0以上のろうそくを付ける
    int minus=k-plus;//まず最初に付けなくてはならない0未満のろうそくの数
    int first=z-minus,end=z+plus-1;//最初の先頭,最後

    int ans=INF;
    
    while(first>=0 && end >= z-1){
        int sum=2*min(abs(a[first]),abs(a[end])) + max(abs(a[first]),abs(a[end]));
        if(first==z || end==z-1) sum = max(abs(a[first]),abs(a[end]));
        ans = min(sum,ans);
        first--,end--;
    }

    cout << ans << endl;

    return 0;
}