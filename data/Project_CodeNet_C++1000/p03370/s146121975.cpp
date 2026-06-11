#include <iostream>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;
#define all(v) (v).begin(),(v).end()

int main(){
  	int N, X;
  	cin >> N >> X;
  	vector<int> m(N);
  	for (int i=0;i<N;i++) cin >> m[i];
  	int m_min = *min_element(all(m));
  	int m_sum = accumulate(all(m), 0);
  	cout << (X - m_sum) / m_min + N << endl;
}