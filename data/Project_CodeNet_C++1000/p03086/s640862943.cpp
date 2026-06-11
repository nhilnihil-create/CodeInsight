#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    string  acgt = "ACGT";
    int cnt = 0;
    int res = 0;
    
    for (int i=0; i < s.size(); i++) {
        for (int j = 0; j < acgt.size(); j++) {
            if (s[i] == acgt[j]){
                cnt++;
                if (cnt > res) {
                    res = cnt;
                }
                break;
            }
            else if (j == acgt.size()-1) cnt = 0;
        }
    }

    cout << res << endl;

}