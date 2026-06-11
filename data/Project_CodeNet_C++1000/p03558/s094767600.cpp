#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef long long ll;

int main(void){
    ll k;
    cin>>k;
    int mi[101010],cur,cost,next;
    priority_queue<pair<int,int>> q;
    for(int i=0;i<k;i++)mi[i]=1<<30;
    for(int i=1;i<10;i++){
        mi[i%k]=min(mi[i%k],i);
        q.push({-mi[i%k],i%k});
    }
    while(q.size()){
        cur=q.top().second;
        cost=-q.top().first;
        //cout<<cur<<" "<<cost<<endl;
        q.pop();
        if(cost!=mi[cur]) continue;
        for(int i=0;i<10;i++){
            next=(cur*10+i)%k;
            if(mi[next]>cost+i){
                mi[next]=cost+i;
                //cout<<"@"<<next<<" "<<cost+i<<endl;
                q.push({-mi[next],next});
            }
        }
    }
    cout<<mi[0]<<endl;
    
    return 0;
}
