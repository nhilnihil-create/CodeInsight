#include<bits/stdc++.h>
using namespace std;
signed main(){
    int n;
    int d[105];
    int s=0;
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>d[i];
    }
    sort(d,d+n);

    for(int i=0; i<n; i++){
    if(i!=0&&d[i]==d[i-1]){
      continue;
    }
    s++;
    }
    cout<<s<<"\n";
    return 0;
}