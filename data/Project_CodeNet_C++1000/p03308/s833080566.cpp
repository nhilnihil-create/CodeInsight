#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

int main() {
  	int N, min, max, a;
    cin >> N;
    for (int i=0; i<N; i++){
    	if (i==0){
        	cin >> a;
        	min=a;
        	max=a;
        }
        else{
        	cin >> a;
            if (a<min) min=a;
            if (max<a) max=a;
        }
    }
    cout << max-min << endl;
}
