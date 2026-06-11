#include<iostream>
#include<set>
using namespace std;

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    set<string> t;
    int n = s.length();
    for(int i = 0; i < n; i++){
        for(int j = 1; j <= k && i+j <= n; j++){
            t.insert(s.substr(i,j));
        }
    }
    auto it = t.begin();
    k--;
    while(k--){
        it++;
    }
    cout << *it << endl;
    return 0;
}