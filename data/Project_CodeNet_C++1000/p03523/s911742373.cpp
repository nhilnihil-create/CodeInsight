#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    cin >> s;
    s.push_back('.');
    string t = "AKIHABARA";
    for(int i = 0; i < 9; i++){
        if(s[i] != t[i]) s.insert(i, "A");
    }
    s.pop_back();
    if(s == t) cout << "YES" << endl;
    else cout << "NO" << endl;
}
