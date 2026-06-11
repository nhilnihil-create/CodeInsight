#include<iostream>
#include<map>
using namespace std;

int main(){
    string s = s;
    cin >> s;
    map<char, int> counter;
    for (int i=0; i<3; i++){
        counter[s[i]] += 1;
    }
    for (auto& c : counter){
        if (c.second > 1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}