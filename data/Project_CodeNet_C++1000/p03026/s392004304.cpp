#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> vec[n+1];
    for(int i = 0; i < n-1; i ++)
    {
        int x, y;
        cin >> x >> y;
        vec[x].push_back(y);
        vec[y].push_back(x);
    }
    vector<int> c(n), d(n+1, 0);
    for(int i = 0; i < n; i++) cin >> c[i];
    sort(c.rbegin(), c.rend());
    int ans = 0, k = 0;
  	queue<int> q;
  	q.push(1);
  	while(!q.empty()){
    	int top = q.front();
      	q.pop();
      	d[top] = c[k++]; 
      	ans += d[top];
      	for(auto x: vec[top])
        {
        	if(d[x] == 0)  q.push(x);
        }
    }	
  	cout << ans - c[0] << endl;
  	for(int i = 1; i <= n; i++) cout << d[i] << " " ;
}
