#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n;
    vector<string> s(n);
    for(int i = 0;i < n;i++)cin >> s.at(i);
    cin >> m;
    vector<string> t(m);
    for(int i = 0;i < m;i++){
        cin >> t.at(i);
    }
    vector<int> count(n, 0);
    for(int i = 0;i < n;i++){
        string memo = s.at(i);
        for(int j = 0;j < n;j++){
            if(memo == s.at(j))count.at(i)++;
        }
        for(int j = 0;j < m;j++){
            if(memo == t.at(j))count.at(i)--;
        }
    }
    sort(count.begin(), count.end());
    if(count.at(n - 1) <= 0)cout << 0 << endl;
    else cout << count.at(n - 1) << endl;
}