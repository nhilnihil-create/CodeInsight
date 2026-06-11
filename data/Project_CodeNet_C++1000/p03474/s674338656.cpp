#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <string.h>

using namespace std;

int main()
{
    string s;
    int a, b;
    cin >> a >> b;
    cin >> s;
    
    string ans = "Yes";
    for (int i=0; i<a+b+1; i++) {
        if (i == a) {
            if (s[i] != '-') {
                ans = "No";
                break;
            }
        }
        else {
            if (s[i] == '-') {
                ans = "No";
                break;
            }
        }
   }
   cout << ans << '\n';
   
   return 0;
}