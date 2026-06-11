#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int N;
    int max=0;
    int min=1000000000;
    cin >> N;
    
    vector <int> arr(N);
    
    for(int i=0; i<N; i++){
        cin >> arr.at(i);
        if(max < arr.at(i)) max = arr.at(i);
        if(min > arr.at(i)) min = arr.at(i);   
    }
    
    cout << max - min << endl; 
    
    return 0;
}