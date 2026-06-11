#include<bits/stdc++.h>
const int N = 100000+5;
using namespace std;
int vis[N];
int main() {
    int n;
    scanf("%d",&n);
    deque<pair<int,int> > Q;
    Q.push_front(make_pair(1,1));
    while(!Q.empty()){
        pair<int,int> temp=Q.front();
        Q.pop_front();
        if(!vis[temp.first]){
            vis[temp.first]=true;
            if(temp.first==0){
                printf("%d\n",temp.second);
                break;
            }
            Q.push_front(make_pair((temp.first*10)%n,temp.second));
            Q.push_back(make_pair((temp.first+1)%n,temp.second+1));
        }
    }
    return 0;
}