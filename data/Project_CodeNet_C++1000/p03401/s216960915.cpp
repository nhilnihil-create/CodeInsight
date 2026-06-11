#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

 
int main() {
    int n;
    cin>>n;
    vector<int> A(n);
    rep(i,n)cin>>A[i];
    int sum=abs(A[0]);
    rep(i,n-1)sum+=abs(A[i+1]-A[i]);
    //最初と最後だけ例外処理
    cout<<sum-abs(A[0])-abs(A[1]-A[0])+abs(A[1])+abs(A[n-1])<<endl;
    for(int i=1;i<n-1;i++){
        cout<<sum-abs(A[i]-A[i-1])-abs(A[i+1]-A[i])+abs(A[i+1]-A[i-1])+abs(A[n-1])<<endl;
    }
    cout<<sum-abs(A[n-1]-A[n-2])+abs(A[n-2])<<endl;
}