#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> antenna(5);
    for(auto i = antenna.begin(); i < antenna.end(); i++){
        cin >> *i;
    }
    int k;
    cin >> k;
    for(auto i = antenna.begin(); i < antenna.end(); i++){
        for(auto j = antenna.begin() + distance(antenna.begin(), i) + 1; j < antenna.end(); j++){
            if(abs(*i - *j) > k){
            cout << ":(" << endl;
            return 0;
        }
        }
    }
    cout << "Yay!" << endl;
    return 0;
}