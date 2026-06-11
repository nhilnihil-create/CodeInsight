#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    priority_queue<int> q;
    ll extra=0,ans=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        if(a[i]<b) ans++,extra+=b-a[i];
        else q.push(a[i]-b);
    }
    while(extra>0){
        if(q.empty()){
            cout<<-1<<endl;
            return 0;
        }
       
        int x=q.top();
        q.pop();
       extra-=x;
        if(x!=0) ans++; 
    }
    cout<<ans<<endl;
}
