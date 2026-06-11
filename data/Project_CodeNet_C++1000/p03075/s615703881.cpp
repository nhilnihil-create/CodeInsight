#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
    vector<int> A(5);
    for(int i=0;i<5;i++)cin>>A[i];
    int k; cin>>k;
    sort(A.begin(),A.end());
    cout<<((A[4]-A[0])<=k ? "Yay!" : ":(")<<endl;
}