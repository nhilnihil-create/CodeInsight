#include <bits/stdc++.h>

using namespace std;

int main() {
    string S;
    cin >> S;
    int counter = 0;
    for(char s : S){
        if(s == 'o') counter++;
    }
    cout << 700+100*counter << endl;
}