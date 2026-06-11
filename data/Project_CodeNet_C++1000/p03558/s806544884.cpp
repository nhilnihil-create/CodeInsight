//
//  main.cpp
//  ABC077D
//  dequeを使う
// 01BFS
#include <iostream>
#include <deque> // dequeを使う
int cost[100005]={};
bool flag[100005]={};
using namespace std;
int main(int argc, const char * argv[]) {
    int k;
    cin>>k;
    for(int i=0;i<k;i++){
        cost[i]=50;
    }
    cost[1]=1;
    deque<int> dq;
    dq.push_front(1);
    int now=1;
    while(now!=0){
        if(flag[now]==false){
            if(now*10%k!=now){
                cost[now*10%k]=min(cost[now*10%k],cost[now]);
                dq.push_front(now*10%k);
            }
            cost[(now+1)%k]=min(cost[(now+1)%k],cost[now]+1);
            dq.push_back((now+1)%k);
            flag[now]=true;
            now=dq.front(); // 先頭から取り出して
            dq.pop_front(); // 先頭を取り除く
        } else {
            now=dq.front(); // 先頭から取り出して
            dq.pop_front(); // 先頭を取り除く
        }
    }
    cout<<cost[0]<<endl;
    return 0;
}
