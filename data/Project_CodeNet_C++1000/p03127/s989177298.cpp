#include<iostream>
#include <queue> 
using namespace std;


int main() {
  vector <int> dtom{-1, 2,5,5,4,5,6,3,7,6 };
  int n, m;
  cin >> n;
  long long int min = 10000000000;
  
  priority_queue<int> pq;
  int temp;
  for(int i=0; i < n; i++) {
   	cin >> temp;
    pq.push(temp);
  }
  while(pq.size() != 1) {
  	int n1 = pq.top();
    pq.pop();
    int n2 = pq.top();
    pq.pop();
    n1 = n1 % n2;
    if(n1 != 0)
    	pq.push(n1);
    pq.push(n2);
    
  }
  cout << pq.top();
  return 0;
}