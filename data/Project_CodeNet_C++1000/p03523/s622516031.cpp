#include <bits/stdc++.h>
using namespace std;
int main(void){
    string S;
    cin >> S;
    string a[16] = {"AKIHABARA", "AKIHBARA", "AKIHABRA", "AKIHABAR", "AKIHBRA", "AKIHBAR", "AKIHBR", "AKIHABR", "KIHBR", "KIHBRA", "KIHBAR", "KIHBARA", "KIHABR", "KIHABRA", "KIHABAR", "KIHABARA"};
 
    for (int i = 0; i < 16; i++) {
        if (S == a[i]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}