#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
  	int N, x;
  	cin >> N >> x;
  	vector<int> a(N);
  	for(int i=0;i<N;i++) cin >> a[i];
  	sort(a.begin(), a.end());
  	int counter = 0;
  	for(int i=0;i<N;i++){
      	x -= a[i];
	    if(x == 0){
    	    ++counter;
	        break;
        }
        else if(x < 0) break;
      	else ++counter;
    }
  	if(x > 0) --counter;
  	cout << counter << endl;
}