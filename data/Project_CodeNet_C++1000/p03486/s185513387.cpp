#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    string a, b;
    cin >> a >> b;
    vector<char>s(a.size());
    vector<char>t(b.size());
    for(int i=0; i<a.size(); i++){
        s[i] = a[i];
    }
    for(int i=0; i<b.size(); i++){
        t[i] = b[i];
    }
    sort(s.begin(),s.end());
    sort(t.rbegin(),t.rend());
    for(int i=0; i<a.size(); i++){
        a[i] = s[i];
    }
    for(int i=0; i<b.size(); i++){
        b[i] = t[i];
    }
    if(s<t){
        puts("Yes");
    }else{
        puts("No");
    }
    return 0;
}