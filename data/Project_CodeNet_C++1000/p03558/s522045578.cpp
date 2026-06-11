#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n, m) for (int i = n; i >= m; i--)


struct Node{
	int point;
	int dis;
	bool done;
	Node *mul;
	Node *add;
};

int main()
{
	int k;
	cin >> k;
	deque<pair<int, int> > c;
	vector<Node> a(k);
	rep(i, k){
		if(i==k-1){
			a[i]={i, INT_MAX, false, &a[(i*10)%k], &a[0]};
			break;
		}
		a[i] = {i, INT_MAX, false, &a[(i*10)%k], &a[i+1]};
	}

	a[1].dis = 1;
	c.push_back(make_pair(1, 1));
	while(c.size()!=0){
		pair<int, int> tmp = c.front();
		c.pop_front();
		// cout << "tmp a[0] "<< a[0].dis << endl;
		if(a[tmp.first].dis > tmp.second){
		a[tmp.first].dis = tmp.second;}
		a[tmp.first].done = true;
		if(a[tmp.first].mul->done == false){
			c.push_front(make_pair(a[tmp.first].mul->point, tmp.second));
			// cout << "muli:" << a[tmp.first].mul->point << " " << tmp.second <<endl;
		}
		if(a[tmp.first].add->done == false){
			c.push_back(make_pair(a[tmp.first].add->point, tmp.second+1));
			// cout << "addi:" << a[tmp.first].add->point << " " << tmp.second+1 <<endl;
		}

		// cout << "tmp2 a[0] "<< a[0].dis << endl;
	}

	cout << a[0].dis << endl;
}

