#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k,c=0,i;
    cin>>n>>k;
    int suu[n];
    for(i=0;i<n;i++){
      cin>>suu[i];
    }
    n--;
    k--;
    int ans=(n+k-1)/k;
    cout<<ans<<endl;
}