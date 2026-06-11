#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    int k;
    cin >> k;
    vector<string> v;
    set<string> set_s;
    for(int i=1; i<=5; i++){
        for(int j=0; j+i-1<s.size();j++){
            string a;
            a = s.substr(j,i);
            if(!set_s.count(a)){
                v.push_back(a);
                set_s.insert(a);
            }
        }
    }
    sort(v.begin(), v.end());
    cout << v.at(k-1) << endl;
}