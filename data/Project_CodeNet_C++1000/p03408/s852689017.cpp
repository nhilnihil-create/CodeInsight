#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,M;
    cin >> N;
    vector<string>s(N);
    set<string> word;
    for(int i = 0; i < N; i++){
        cin >> s.at(i);
        word.insert(s.at(i));
    }
    cin >> M;
    vector<string>t(M);
    for(int i = 0; i < M; i++){
        cin >> t.at(i);
    }
    int max = 0;
    for(string w : word){
        int score = 0;
        for(int i = 0; i < N; i++){
            if(w == s.at(i))score++;
        }
        for(int i = 0; i < M; i++){
            if(w == t.at(i))score--;
        }
        if(max < score)max = score;
    }
    cout << max << endl;
    return 0;
}