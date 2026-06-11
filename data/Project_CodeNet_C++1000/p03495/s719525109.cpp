#include<bits/stdc++.h>
using namespace std;
int s[200005];
int main(){
    int n,k;
    cin >> n >> k;
    int a;
    int ans=0;
    int tmp=0;
    for(int i=0;i<n;i++){
        cin >> a;
        if(s[a]==0)tmp++;
        s[a]++;
    }
    if(tmp<=k){
        cout << 0 << endl;
        return 0;
    }
    sort(s,s+n+1);
    int count=0;
    int i=0;
    while(count<tmp-k){
        if(s[i]>0){
            ans+=s[i];
            count++;
        }
        i++;
    }
    cout << ans;
}