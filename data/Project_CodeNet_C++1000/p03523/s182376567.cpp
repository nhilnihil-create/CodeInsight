#include <iostream>
#include <string>
using namespace std;
int main () {
    int cnt=0;
    string N, M, check[20]={"KIHBR", "AKIHBR", "KIHABR", "KIHBAR", "KIHBRA", "AKIHABR", "AKIHBAR", "AKIHBRA", "KIHABAR", "KIHABRA", "KIHBARA", "AKIHABAR", "AKIHABRA", "AKIHBARA","KIHABARA", "AKIHABARA" };
    cin >> N;
    for (int i=0;i<16;i++){
        if (N==check[i])
            cnt++;
    }
    cnt ? cout << "YES" : cout << "NO";
    return 0;
}