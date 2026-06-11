#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
deque< pair<long long,long long> >Que;
int H,T;
bool Visit[100050];
long long K;
int main(){
	scanf("%lld",&K);
	Que.push_back(make_pair(1,1));
	while(!Que.empty()){
		pair<long long,long long> Now=Que.front();
		Que.pop_front();
		if(Visit[Now.second]){
			continue;
		}
		Visit[Now.second]=1;
		
		if(Now.second%K==0){
			printf("%lld\n",Now.first);
			break;
		}
		Que.push_front(make_pair(Now.first,(Now.second*10)%K));
		Que.push_back(make_pair(Now.first+1,(Now.second+1)%K));
	}
	return 0;
	//AC!
}