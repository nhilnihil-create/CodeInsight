#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;


int main() {
    int N;
    cin>>N;
    int sum=0;
    int a[N+2];
    a[0]=0;
    a[N+1]=0;
    for(int i=1;i<=N;i++){
        cin>>a[i];
        sum+=abs(a[i]-a[i-1]);
    }
    sum+=abs(a[N]);
    for(int i=1;i<=N;i++){
        cout<<sum-abs(a[i-1]-a[i])-abs(a[i]-a[i+1])+abs(a[i-1]-a[i+1])<<endl;
    }
}