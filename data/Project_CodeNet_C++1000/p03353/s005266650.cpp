#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string s;
    int K;
    cin >> s >> K;

    set<string> ss;
    for(int i=0,l=1;i<K;i++,l++) {
        for(int j=i;j<s.size();j++) {
            ss.insert(s.substr(j-l+1,l));
        }
    }
//    ss.sort(ss.begin(), ss.end());
    set<string>::iterator it = ss.begin();
    for(int i= 1;i<K;i++) {
        it++;
    }
    cout << *it << endl;

    return 0;
}
