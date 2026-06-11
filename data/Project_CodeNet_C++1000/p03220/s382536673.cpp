#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define all(v) (v).begin(),(v).end()

int main(){
  	int N, T, A;
  	cin >> N >> T >> A;
  	double H_id = (T - A) / 0.006;
    vector<double> H_i(N);
  	for (int i = 0; i < N; i++){
      	cin >> H_i[i];
      	H_i[i] = abs(H_i[i]-H_id);
    }
  	vector<double>::iterator iter = min_element(all(H_i));
  	cout << distance(H_i.begin(), iter)+1 << endl;
}