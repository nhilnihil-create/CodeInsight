#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    if(s == "AKIHABARA" 
    || s == "KIHABARA" 
    || s == "AKIHBARA" 
    || s == "AKIHABRA" 
    || s == "AKIHABAR" 
    || s == "KIHBARA" 
    || s == "KIHABARA" 
    || s == "AKIHABRA" 
    || s == "KIHABAR"
    || s == "AKIHBRA"
    || s == "AKIHBAR"
    || s == "AKIHABR"
    || s == "KIHBRA"
    || s == "KIHBAR"
    || s == "KIHABR"
    || s == "AKIHBR"
    || s == "KIHBR"
    )
     {
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}
