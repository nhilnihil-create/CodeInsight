#include <iostream>
#include <bits/stdc++.h>
#include <string>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int main() {
    string s;
    cin >> s;
    int i = 0;
    for (char x: s){
        if (x == '+'){
            i++;
        } else {
            i--;
        }
    }
	cout << i << endl;
}
