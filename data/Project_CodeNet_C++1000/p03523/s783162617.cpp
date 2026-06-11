#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007

int main(){
    string s; cin >> s;
    string t[16] = {"AKIHABARA", "KIHABARA", "AKIHBARA", "AKIHABRA",
                  "AKIHABAR", "KIHBARA", "KIHABRA", "KIHABAR",
                  "AKIHBRA", "AKIHBAR", "AKIHABR", "KIHBRA",
                  "KIHBAR", "KIHABR", "AKIHBR", "KIHBR"};
    for(int i = 0; i < 16; i++){
        if(t[i] == s){
            cout << "YES" << endl; return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}