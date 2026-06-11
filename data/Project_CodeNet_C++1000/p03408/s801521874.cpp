#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<string> s;
    vector<int> c;
    for(int i=0;i<N;i++){
        string t;
        cin >> t;
        bool f = true;
        for(int j=0;j<s.size();j++){
            if(s.at(j) == t){
                c.at(j)++;
                f = false;
                break;
            }
        }
        if(f){
            s.push_back(t);
            c.push_back(1);
        }
    }
    int M;
    cin >> M;
    
    for(int i=0;i<M;i++){
        string t;
        cin >> t;
        for(int j=0;j<s.size();j++){
            if(s.at(j) == t){
                c.at(j)--;
                break;
            }
        }
    }
    int max = 0;
    for(int i=0;i<c.size();i++){
        if(c.at(i) > max) max = c.at(i);
    }
    cout << max << endl;
}
