#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N, T;
    cin >> N >> T;

    vector<int>C;
    int c, t;
    for(int i=0; i<N; i++){
        cin >> c >> t;
        if(t<=T){
            C.push_back(c);
        }
    }
        

    sort(C.begin(), C.end());

    if(C.size()==0){
        cout << "TLE" << endl;
        return 0;
    } 

    cout << C[0] << endl;

    return 0;
}