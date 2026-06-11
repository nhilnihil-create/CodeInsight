#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
using namespace std;
int main(void){
    string s,t;
    cin >> s >> t;
    sort(s.begin(),s.end());
    sort(t.begin(),t.end(),greater<>());
    if(s.compare(t)>=0)cout << "No";
    else cout << "Yes";
    cout << "\n";
    return 0;
}