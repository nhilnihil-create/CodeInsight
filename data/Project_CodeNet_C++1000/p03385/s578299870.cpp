#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;

int main(){
    vector<char> s(3);
    for(int i=0;i<3;i++){
        cin >> s.at(i);
    }
    sort(s.begin(),s.end());
    if(s.at(0)=='a') {
        if(s.at(1)=='b'){
            if(s.at(2)=='c'){
                cout << "Yes" << endl;
            }
            else {
                cout << "No" << endl;
            }
        }
        else {
            cout << "No" << endl;
        }
    }
    else {
        cout << "No" << endl;
    }
}
