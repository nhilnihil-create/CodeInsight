#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(),(v).end()
using namespace std;



int main(){
  	int N;
  	cin >> N;
  	vector<int> a(N);
  	for(int i=0;i<N;i++) cin >> a[i];
  	sort(all(a), greater<int>());
  	int Alice = 0, Bob = 0;
  	for(int i=0;i<N;i++){
      	if(i%2 == 0) Alice += a[i];
      	else Bob += a[i];
    }
  	cout << Alice - Bob << endl;
}