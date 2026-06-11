#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, i;
    string w[200100];
    char tmp='a';
    map<string, int> mp;
    cin >> n;
    for(i=0;i<n;i++){
        cin >> w[i];
    }

    for(i=0;i<n;i++){
        if(tmp!=w[i][0] && i!=0){
            cout << "No" <<endl;
            return 0;
        }
        mp[w[i]]++;
        if(mp[w[i]]!=1){
            cout << "No" <<endl;
            return 0;
        }
        tmp=w[i][w[i].size()-1];
    }
    cout << "Yes" <<endl;
    return 0;
}
