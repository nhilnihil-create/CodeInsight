#include<bits/stdc++.h>
using namespace std;
deque<pair<int,int> > p;
bool flag[100000001];
int l;
void suanfa(){
    while(p.size()) {
        pair<int,int> 
		now=p.front(); 
		p.pop_front();
        if(flag[now.first]) 
		    continue;
        flag[now.first]=true;
        if(!now.first){
            cout<<now.second<<endl;
            return;
        }
        p.push_front(make_pair(now.first*10%l,now.second));
        p.push_back(make_pair((now.first+1)%l,now.second+1));
    }
}
int main() {
    cin>>l;
    p.push_front(make_pair(1,1));
    suanfa();
    return 0;
}