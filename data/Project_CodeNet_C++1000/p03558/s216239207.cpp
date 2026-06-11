#include<iostream>
#include<queue>
using namespace std;
#define P pair<int,int>

deque<P> q;
bool did[100010];

int main(){
  int k;

  cin>>k;

  q.push_front(P(1,1));

  while(1){
    P p = q.front(); q.pop_front();
    if(did[p.first]) continue;
    did[p.first] = true;
    if(p.first==0){
      cout<<p.second<<endl;
      break;
    }
    q.push_back(P((p.first+1)%k,p.second+1));
    q.push_front(P((p.first*10%k),p.second));
  }

  return 0;
}


