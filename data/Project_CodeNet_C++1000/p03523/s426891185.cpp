#include<bits/stdc++.h>
using namespace std;
#define itn int

int main(void){
    string s,t = "AKIHABARA";
    cin >> s;
    
    if(s.size() > t.size())cout << "NO";
    else if(s == t)cout << "YES";
    else {
        if(s.size() == 5){
            if(s == "KIHBR")cout << "YES";
            else cout << "NO";
        } else if(s.size() == 6){
            if(s == "AKIHBR" || s == "KIHABR" || s == "KIHBAR" || s == "KIHBRA")cout << "YES";
            else cout << "NO";
        } else if(s.size() == 7){
            if(s == "AKIHABR" || s == "AKIHBAR" || s == "AKIHBRA" || s == "KIHABAR" || s == "KIHABRA" || s == "KIHBARA")cout << "YES";
            else cout << "NO";
        } else {
            if(s == "AKIHABAR" || s == "AKIHBARA" || s == "KIHABARA")cout << "YES";
            else cout << "NO";
        }
    }
}