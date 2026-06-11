#include<iostream>
#include<vector>
#include<numeric>
#include<queue>
using namespace std;
using ll = long long;

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    vector<bool> ok(n,false);
    priority_queue<pair<int,int>> q;
    ll c=0,ans=0;
    for(int i=0;i<n;i++) cin>>a[i];
    for(int i=0;i<n;i++){
        int b;
        cin>>b;
        if(a[i]<b) ans++,c+=b-a[i];
        else q.push(make_pair(a[i]-b,i));
    }
    while(c>0){
        if(q.empty()){
            cout<<-1<<endl;
            return 0;
        }
        int i=q.top().second;
        int x=q.top().first;
        q.pop();
        c-=x;
        if(x!=0) ans++; 
    }
    cout<<ans<<endl;
}