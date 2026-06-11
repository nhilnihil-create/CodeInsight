#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector <string>Name = {};
    vector <int>Number = {};
    int i;
    for(i = 0;i < n;i++){
        string s;
        cin >> s;
        int j;
        for(j = 0;j < Name.size();j++){
            if(s == Name.at(j)){
                Number.at(j)++;
                break;
            }
        }
        if(j == Name.size()){
            Name.push_back(s);
            Number.push_back(1);
        }
    }
    int m;
    cin >> m;
    for(i = 0;i < m;i++){
        string t;
        cin >> t;
        int j;
        for(j = 0;j < Name.size();j++){
            if(t == Name.at(j)){
                Number.at(j)--;
                break;
            }
        }
        if(j == Name.size()){
            Name.push_back(t);
            Number.push_back(-1);
        }
    }
    
    int max = 0;
    for(i = 0;i < Number.size();i++){
        if(max < Number.at(i)){
            max = Number.at(i);
        }
    }

    cout << max << endl;

}