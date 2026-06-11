#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin >> s;

    int cnt[3] = {};
    for(char x : s) cnt[x-'a']++;
    sort(cnt, cnt+3);

    if(cnt[2]-cnt[0] <= 1)  cout << "YES" << endl;
    else                    cout << "NO" << endl;
    
    return 0;
}