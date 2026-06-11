#include<iostream>
#include<deque>
#include<map>
using namespace std;

typedef pair<int,int> Pair;
typedef map<int,bool> Map;
Map imap;

void work(void)
{
	int k=0;
	cin>>k;
	deque<Pair>deq;
	deq.push_back(make_pair(1,1));
	while(!deq.empty())
	{
		Pair x=deq.front();
		deq.pop_front();
		if(imap[x.first])
			continue;
		imap[x.first]=true;
		if(x.first==0)
		{
			cout<<x.second<<endl;
			break;
		}
		deq.push_front(make_pair((x.first*10)%k,x.second));
		deq.push_back(make_pair((x.first+1)%k,x.second+1));
	}
	return;
}

int main(int argc,char *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL); 
	work();
	return 0;
}

