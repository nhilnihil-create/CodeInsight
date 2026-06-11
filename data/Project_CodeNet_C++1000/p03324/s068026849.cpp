#include <iostream>
using namespace std;

int cnt(int x){
    if (x%100!=0) return 0;
    return cnt(x/100)+1;
}
int main() {
	int D, N;
	cin >> D >> N;
	int count=0;
	for (int i=1; ; i++){
	    if (cnt(i)==D){
	        count++;
	    }
	    if (count==N){
	        cout << i << endl;
	        return 0;
	    }
	}
}