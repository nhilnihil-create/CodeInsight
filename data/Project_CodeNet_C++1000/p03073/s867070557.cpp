#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
 
int main() {
    string s;
    cin >> s;
    int count=0;
    for(int i=0;i<s.size();i+=2){
        if(s.at(i)=='0')count++;
    }
    for(int i=1;i<s.size();i+=2){
        if(s.at(i)=='1')count++;
    }
    int a=s.size();
    cout << min(count,(a-count)) << endl;
}