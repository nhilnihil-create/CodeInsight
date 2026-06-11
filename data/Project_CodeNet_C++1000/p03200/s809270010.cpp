#include <bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin >> s;

    map<int, int> wpos;
    for(int i=0; i<s.size(); i++){
        if(s.at(i) == 'W'){
            int buf = i+1;
            wpos[buf]++;
        }
    }
    long long pos = 1, cnt = 0;
    for(auto p: wpos){
        auto key = p.first;
        cnt += key - pos;
        pos++;
    }
    cout << cnt << endl;
    return 0;
}