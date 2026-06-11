#include <bits/stdc++.h>
using namespace std;
 
int main() {
    vector<char> s(3);
    for (int i=0;i<3;i++){
        cin >> s.at(i);
    }
    
    int count = 0;
    for (int i=0;i<3;i++){
        if(s.at(i) == '1'){
            count++;
        }
    }
    cout << count << endl;
}