#include <iostream>
#include <string>

using namespace std;

int main() { 
    string s;
    cin >> s;
    int n = s.size();
    int ret = n;
    for (int i = 0; i < n - 1; i++) {
        if(s[i]!=s[i+1]){
            ret = min(ret, max(i + 1, n - i - 1));
        }
    }
    cout << ret << endl;
}