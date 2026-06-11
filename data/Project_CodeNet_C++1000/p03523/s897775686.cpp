#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string S_input;
string S = "AKIHABARA";
int size_S = S.size();
vector<string> v;

int create(string s_ch, int i);

int main() {


    cin >> S_input;
    
    create("", 0);

    auto result = find(v.begin(), v.end(), S_input);
    if (result == v.end()) {
        cout << "NO" << endl;
    } 
    else {
        cout << "YES" << endl;
    }

}


int create(string s_ch, int i) {
    
    if (i == size_S) {
        v.push_back(s_ch);
        return 0;
    }
    
    if (S[i] == 'A') {
        create(s_ch, i+1);
        s_ch += S[i];
        create(s_ch, i+1);
    }
    else {
        s_ch += S[i];
        create(s_ch, i+1);
    }

    return 0;
}
