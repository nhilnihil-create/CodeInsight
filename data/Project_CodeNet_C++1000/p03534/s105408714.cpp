#include <bits/stdc++.h>

using namespace std;

int a[3];
int main(){
    string s;
    cin>>s;
    for(auto ch:s) a[ch-'a']++;
    sort(a,a+3);
    cout<<((a[2]>a[0]+1)?"NO":"YES");
}
