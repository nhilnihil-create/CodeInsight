#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    int k;
    cin >> s >> k;
    int n=s.size();
    vector<string> slist;
    for(int i = 1; i <= min(k,n); i++) {
        for(int j = 0; j < n-i+1; j++) {
            string tmp;
            tmp=s.substr(j,i);
            slist.emplace_back(tmp);
        }
    }
    sort(slist.begin(),slist.end());

//    for(int i = 0; i < slist.size(); i++) {
//        cout << slist[i] << "\n";
//    }

    string ref=slist[0];
    int idx=1;
    int count=1;
    while(count<k) {
        if(ref!=slist[idx]){
            count++;
            ref=slist[idx];
        }
        idx++;
    }
    cout << ref << "\n";
    return 0;
}