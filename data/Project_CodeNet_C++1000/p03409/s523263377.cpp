#include <bits/stdc++.h>
using namespace std;
 
int main() {
    int n,x,y,bx,by;
    int ans=0;
    cin>>n;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>r;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>b;
    set<int>rys;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        r.push(pair(x,y));
    }
    for(int i=0;i<n;i++){
        cin>>x>>y;
        b.push(pair(x,y));
    }
    while(b.size()>0){
        tie(bx,by)=b.top();
        b.pop();
        while(r.size()>0&&r.top().first<bx){           
            rys.insert(r.top().second);
            r.pop();                    
        }
        if(rys.size()==0)continue;
        auto itr=rys.upper_bound(by);
        if(itr==rys.begin())continue;
        ans++;
        rys.erase(prev(itr));

    }
    cout<<ans;
    


}