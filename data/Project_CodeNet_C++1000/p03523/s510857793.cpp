#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string ans="NO";
    if(s=="AKIHABARA") ans="YES";
    else if(s=="KIHABARA") ans="YES";
    else if(s=="AKIHBARA") ans="YES";
    else if(s=="AKIHABRA") ans="YES";
    else if(s=="AKIHABAR") ans="YES";
    else if(s=="KIHBARA") ans="YES";
    else if(s=="KIHABRA") ans="YES";
    else if(s=="KIHABAR") ans="YES";
    else if(s=="AKIHBRA") ans="YES";
    else if(s=="AKIHBAR") ans="YES";
    else if(s=="AKIHABR") ans="YES";
    else if(s=="KIHBRA") ans="YES";
    else if(s=="KIHBAR") ans="YES";
    else if(s=="KIHABR") ans="YES";
    else if(s=="AKIHBR") ans="YES";
    else if(s=="KIHBR") ans="YES";
    cout << ans << endl;
}