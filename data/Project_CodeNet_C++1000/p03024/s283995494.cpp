#include <bits/stdc++.h>
using namespace std;
int main() {
    string s ; cin>>s;
    int co = 0;
    for(int i = 0; i < s.size(); ++i)if(s[i] == 'o')co++;
    int baki = 15 - (int)s.size();
    puts((co + baki >= 8)?"YES":"NO");
}
