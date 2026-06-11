#include <iostream>

using namespace std;

int main() {
    int a, b, c, x, count = 0;
    cin >> a >> b >> c >> x;
	for (int i = 0; i < a+1; i++){
    	for (int j = 0; j < b+1; j++){
        	if((x - 100*j - 500*i)>=0 & (x-100*j - 500*i)/50 <= c){
            	count++;
            }
        }
    }
  
    cout << count << endl;
  return 0;
}