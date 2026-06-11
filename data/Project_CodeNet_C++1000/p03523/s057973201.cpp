#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;
#define ll int64_t
#define REP(i, n) for (int i=0; i<n; i++)

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    string target[] = {"KIHBR", "KIHBRA", "KIHBAR", "KIHBARA",
    "KIHABR", "KIHABRA", "KIHABAR", "KIHABARA",
    "AKIHBR", "AKIHBRA", "AKIHBAR", "AKIHBARA",
    "AKIHABR", "AKIHABRA", "AKIHABAR", "AKIHABARA"};

    string ans = "NO";

    for (int i=0; i<16; i++){
        if (S == target[i]){
            ans = "YES";
        }
    }

    cout << ans << "\n";
}