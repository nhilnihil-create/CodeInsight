#include <iostream>
#include <map>
using namespace std;
int main(){
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for(int i=1; i<n-1; i++){
        int count = 0;
        string a, b;
        a = s.substr(0, i);
        b = s.substr(i, n-i);
        map<char, int>mp;
        for(int j=0; j<i; j++){
            mp[a[j]] = 1;
        }
        for(int j=0; j<n-i; j++){
            if(mp[b[j]]==1){
                count++;
                mp[b[j]]++;
            }
        }
        ans = max(ans, count);
    }
    cout << ans << endl;
    return 0;
}