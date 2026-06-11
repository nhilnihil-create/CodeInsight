#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector <string> s(n),s2(n);
    vector <int> p(n);
    for(int i = 0; i < n; i++){
        cin >> s[i] >> p[i];
        s2[i] = s[i];
    }
    sort(s2.begin(),s2.end());
    s2.erase(unique(s2.begin(),s2.end()),s2.end());
    vector <vector<int>> p2(s2.size(),vector<int>());
    vector <int> ans;
    for(int i = 0; i < s2.size(); i++){
        //cout << s2[i] << endl;
        for(int j = 0; j < n; j++){
            if(s2[i].compare(s[j])==0){
                p2[i].push_back(p[j]);
                //cout << p[j] << " ";
            }
            //cout << endl;
        }
        sort(p2[i].begin(),p2[i].end(),greater<int>());
    }
    for(int i = 0; i < p2.size(); i++){
        for(int j = 0; j < p2[i].size(); j++){
            for(int k = 0; k < n; k++){
                if(p2[i][j]==p[k]){
                    ans.push_back(k);
                }
            }
        }
    }
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i]+1 << endl;
    }

    return 0;
}