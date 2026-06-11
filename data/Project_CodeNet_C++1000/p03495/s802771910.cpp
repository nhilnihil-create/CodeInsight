#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

#define Nfor(N) for(int i=0;i<N;i++) 

int main(){
  	int N, K;
  	cin >> N >> K;
  	vector<int> bA(N, 0);
  	Nfor(N){
      	int A_tmp;
      	cin >> A_tmp;
      	bA[A_tmp - 1]++;
    }
  	sort(bA.rbegin(), bA.rend());
  	int count = accumulate(bA.begin()+K, bA.end(), 0);
  	cout << count << endl;
}