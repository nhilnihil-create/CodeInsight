#include <bits/stdc++.h>
using namespace std;

int main () {
	int N;
  	cin >> N;
  	vector<string> shi(N);
  	vector<int> tensu(N);
  	map<string, int> kazu;
  	
  	for (int i = 0; i < N; i++) {
      string s;
      int p;
      cin >> s >> p;
      shi[i] = s;
      tensu[i] = p;
      kazu[s] += 1;
    }
    for (auto item : kazu) {
      auto key = item.first;
      auto value = item.second;
      map<int, int> ids;
      priority_queue<int> queue;
      for (int i = 0; i < N; i++) {
      	if (shi[i] == key) {
          	int t = tensu[i];
        	ids[t] = i;
          	queue.push(t);
        }
      }
      while (queue.size() > 0) {
      	int top = queue.top();
        queue.pop();
        cout << ids[top] + 1 << endl;
      }
    }
}