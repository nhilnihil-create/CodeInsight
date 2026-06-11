#include<bits/stdc++.h>
using namespace std;
int main(){
    int s;
    cin >> s;
    map<int,int>Map;
    for(int i = 0; i < 1000000; i++) {
        if(Map[s] > 0) {
            cout << i+1 << endl;
            return 0;
        }
        Map[s]++;
        if(s%2 == 0) {
            s/=2;
        }
        else {
            s+=s*2+1;
        }
    }
    cout << s << endl;
}

