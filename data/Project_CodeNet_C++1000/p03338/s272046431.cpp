#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    int max_count=0;
    for (int i=1; i<S.length(); i++){
        int count=0;
        string T=S.substr(0,i);
        string R=S.substr(i);
        for (char j='a'; j<='z'; j++){
            bool foundt=false, foundr=false;
            for (int k=0; k<T.length(); k++) {
                if (T.at(k)==j) foundt=true;
            }
            for (int m=0; m<R.length(); m++) {
                if (R.at(m)==j) foundr=true;
            }
            if (foundt && foundr) count++;
        }
        max_count=max(max_count, count);
    }
    cout << max_count << endl;
}