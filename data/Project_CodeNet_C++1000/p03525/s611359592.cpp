#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << fixed << setprecision(20);
    
    int n;
    cin>>n;
    int a[n];
    int d[25]={};
    d[0]=1;
    for(int i=0;i<n;i++){
        cin>>a[i];
        d[a[i]]++;
        if(d[a[i]]>2){
            cout << 0 << endl;
            return 0;
        }
        if(d[12]>1 || d[0]>1){
            cout << 0 << endl;
            return 0;
        }
    }    
    bool pos =true;
    for(int i=0;i<=12;i++){
        if(d[i]==0) pos = false;
        if(i==0 || i==12 ){
            if(d[i]>=2){
                cout << 0 << endl;
                return 0;
            }
        }else{
            if(d[i]>=3){
                cout << 0 << endl;
                return 0;
            }
        }
    }
    if(pos){
        cout << 1 << endl;
        return 0;
    }
    int ans = 0;
    for(int i=0;i<(1<<n);i++){
        vector<int> v;
        for(int j=0;j<n;j++){
            if(i&(1<<j)){
                v.push_back(a[j]);
            }
            else v.push_back(24-a[j]);
        }
        v.push_back(0);
        sort(v.begin(),v.end());
        int ret=111;
        for(int j=0;j<n;j++){
            ret = min(ret,v[j+1]-v[j]);
            ret = min(ret,24-v[j+1]+v[j]);
        }
        ret = min(ret,(24-v[n]));
        ret = min(ret,v[n]);
        ans = max(ret,ans);
    }
    cout << ans << endl;
    
}