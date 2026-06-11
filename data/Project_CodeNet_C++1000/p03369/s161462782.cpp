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
    int ans=700;
    for(int i=0;i<3;i++){
        if(s.at(i)=='o'){
            ans+=100;
        }
    }
    cout << ans << endl;
}

