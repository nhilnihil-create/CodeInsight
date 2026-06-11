#include <bits/stdc++.h>
using namespace std;

const string YES = "YES";
const string NO = "NO";

void solve(std::string S){
    vector<string> vecs;
    vecs.push_back("KIHBR");
    vecs.push_back("KIHBRA");
    vecs.push_back("KIHBAR");
    vecs.push_back("KIHABR");
    vecs.push_back("AKIHBR");
    vecs.push_back("KIHBARA");
    vecs.push_back("KIHABRA");
    vecs.push_back("KIHABAR");
    vecs.push_back("AKIHBRA");
    vecs.push_back("AKIHBAR");
    vecs.push_back("AKIHABR");
    vecs.push_back("KIHABARA");
    vecs.push_back("AKIHBARA");
    vecs.push_back("AKIHABRA");
    vecs.push_back("AKIHABAR");
    vecs.push_back("AKIHABARA");
    for(auto s: vecs){
        if(s == S){
            cout << YES << endl;
            return;
        }
    }
    cout << NO << endl;
    return;
}

int main(){
    std::string S;
    std::cin >> S;
    solve(S);
    return 0;
}
