/*
      author  : nishi5451
      created : 14.08.2020 21:03:31
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n;
    cin >> n;
    map<string,int> mp;
    string word;
    cin >> word;
    char end = word.back();
    mp[word]++;
    for(int i=1; i<n; i++){
        string word;
        cin >> word;
        if(word.front() != end){
            cout << "No" << endl;
            return 0;
        }
        end = word.back();
        mp[word]++;
        if(mp[word]==2){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}