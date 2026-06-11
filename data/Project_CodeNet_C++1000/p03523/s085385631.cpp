#include <iostream>
using namespace std;
string str[100] = { "KIHBR","AKIHBR","KIHABR","KIHBAR","KIHBRA","AKIHABR",
"AKIHBAR","AKIHBRA","KIHABAR","KIHABRA","KIHBARA",
"AKIHABAR","AKIHABRA","AKIHBARA","KIHABARA","AKIHABARA" }, s;
int main(){
    ios::sync_with_stdio(false);
    cin >> s;
    for (int i = 0; i < 16; i++)
        if (s == str[i])
            return cout << "YES\n", 0;
    cout << "NO\n";
    return 0;
}