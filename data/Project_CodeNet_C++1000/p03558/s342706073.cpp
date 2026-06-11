#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> p;
	  int n;
	  int v[1<<17];
	  p m;
    deque<p> q;
#define M(a,b) make_pair(a,b)
#define N first 
#define S second 
int main()
{
  cin>>n;
  q.push_back(M(1,1));
  while (1)
    {
      m=q.front();
      q.pop_front();
			if (!m.N) break;
			if (v[m.N]) continue;
			v[m.N]=1;
			q.push_front(M(m.N*10%n,m.S));
			q.push_back(M((m.N+1)%n,m.S+1));
    }
	cout<<m.S;
	return 0;
}