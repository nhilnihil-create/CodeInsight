#include <bits/stdc++.h>
using namespace std;

int main(){
    
    int s;
    cin >> s;
    vector<int> a(1000000);
    a.at(0) = s;
    int i = 1;
    while(1){
        if(s%2 == 0){
            s = s/2;
            auto result = find(a.begin(),a.end(),s);
            if (result != a.end()) {
                cout << i+1 << endl;
                return 0;
            }
            a.at(i) = s;
            i += 1;
        }
        else{
            s = 3 * s + 1;
            auto result = find(a.begin(),a.end(),s);
            if (result != a.end()) {
                cout << i+1 << endl;
                return 0;
            }
            a.at(i) = s;
            i += 1;
        }   
    }
}