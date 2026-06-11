#include <bits/stdc++.h>
using namespace std;

bool check(vector<string> words){
    int n = words.size();
    for (int i=0; i<n-1; i++){
        if (words[i].back() != words[i+1].front()){
            return false;
        }
    }
    for(int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (words[i] == words[j]){
                return false;
            }
        }
    }
    return true;
}

int main(void){
    int n;
    cin >> n;
    vector<string> words(n);
    for (int i=0; i<n; i++) cin >> words[i];
    if (check(words)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}