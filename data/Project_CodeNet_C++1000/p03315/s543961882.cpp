#include <bits/stdc++.h>
using namespace std;

string a;
int total;

int main() {
    cin>>a;
    for(int i=0; i<a.length(); i++) {
        if (a[i]=='+') {
            total++;
        } else {
            total--;
        }
    }
    cout << total;
}
