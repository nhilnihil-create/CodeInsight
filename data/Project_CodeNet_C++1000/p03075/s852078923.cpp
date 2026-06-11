#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<int> vec(5);
    for(int i=0; i<5; i++){
        cin >> vec.at(i);
    }
    int k;
    cin >>k;

    sort(vec.begin(),vec.end());

    for(int i=0; i<5; i++){
        for(int j=i+1; j<5; j++){
            if(vec.at(j)-vec.at(i) > k){
                cout << ":(" << endl;
                return 0;
            }
        }
    }
    cout << "Yay!" << endl;
}