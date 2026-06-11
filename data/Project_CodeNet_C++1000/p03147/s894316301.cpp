#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    
    int n;
    cin>>n;
    
    vector<int>h(n);
    vector<int>now(n,0);
    for(int i=0;i<n;i++){
        cin>>h[i];
    }
    
    int ans=0;
    bool loop=true;
    bool need=false;
    int left,right;
    int i=0;
    int tmp=0;
    while(loop){
        if(now[i]<h[i]){
            if(!need){
                tmp=1;
                need=true;
                left=i;
            }
        }
        else{
            if(need){
                right=i;
                for(int j=left;j<right;j++)now[j]++;
                ans++;
                need=false;
            }
        }
        
        i++;
        if(i==n){
            if(!need && tmp==0)break;
            else if(need){
                for(int j=left;j<n;j++)now[j]++;
                ans++;
            }
            i=0;
            tmp=0;
            need=false;
        }
        
    }
    cout<<ans<<endl;
    
    return 0;
}