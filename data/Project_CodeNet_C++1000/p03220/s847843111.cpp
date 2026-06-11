#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;
 
int main() {
    int N;
    int T; //気温最大値
    int A; //平均気温
    
    cin >> N;
    cin >> T;    
    cin >> A;
    
    vector <int> H(N);
    vector <int> M(N);
    
    for(int i=0; i<N; i++){
        cin >> H.at(i);
        M.at(i) = 0;
     }
    
    for(int i=0; i<N; i++){
        M.at(i) = abs(A*1000 - (T * 1000 - H.at(i) * 6));   
    }
    
    //for(int c : M){
      //  cout << "M=" << c << endl;
    //}
    
    int minElementIndex = min_element(M.begin(), M.end()) - M.begin();
    int minElement = *min_element(M.begin(), M.end());
    
    cout << minElementIndex+1 << endl;
    
    return 0;
}