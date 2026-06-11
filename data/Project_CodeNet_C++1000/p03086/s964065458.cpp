#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    int ans=0,m=0;
    vector<int> data{'A','T','G','C'};
    cin >>s;
    for(int i=0;i<s.size();i++){
        m++;
        if(find(data.begin(),data.end(),s[i])==data.end())m=0;
        ans=max(ans,m);
    }
    cout <<ans;
}
