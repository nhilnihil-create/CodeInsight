#include <bits/stdc++.h>
using namespace std;
#define ALL(a) (a).begin(),(a).end()
#define rALL(a) (a).rbegin(),(a).rend()
typedef pair<int, int> Pint;
typedef pair<int64_t, int64_t> Pll;


int main() {
    string S;
    cin >> S;
    vector<string> A = {"KIHBR","KIHBRA","KIHBAR","KIHABR","AKIHBR","KIHBARA","KIHABRA"
                        ,"KIHABAR","AKIHBRA","AKIHABRA","AKIHBAR", "AKIHABAR", "AKIHABRA"
                        ,"AKIHBARA","KIHABARA","AKIHABARA"};
    for (int i = 0; i < 16; i++){
        if (A.at(i) == S){
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
}


