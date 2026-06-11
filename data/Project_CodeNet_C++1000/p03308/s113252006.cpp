#include <iostream>
#include <algorithm>
using namespace std;

 int N;
 int A[210];

int main(){

 cin >> N;
 for(int i=0;i<N;i++) cin >> A[i];

 int min,max;
 max=*max_element(A,A+N);
 min=*min_element(A,A+N);
 cout << max-min << endl;

}
