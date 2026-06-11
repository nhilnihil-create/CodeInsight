#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

vector<string> candidates;
void rec(int ind, string word, string target_word){
    if(ind == 9){
        candidates.push_back(word);
        return;
    } 
    if (target_word[ind] == 'A'){
        rec(ind+1, word+'A', target_word);
        rec(ind+1, word, target_word);
    } else {
        rec(ind+1, word+target_word[ind], target_word);
    }
}

int main(){
    string s;cin>>s;
    rec(0, "", "AKIHABARA");
    if (find(candidates.begin(), candidates.end(), s) != candidates.end()){
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}