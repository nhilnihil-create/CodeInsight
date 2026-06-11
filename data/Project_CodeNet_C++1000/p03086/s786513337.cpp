#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mxn= 5e5+5;
#define mod 1000000007
#define endl '\n'
void rishabh(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
}
int main(){
    set<char> s;
    s.insert('A');    s.insert('G');    s.insert('C');    s.insert('T');
    string str;
    cin>>str;
    int temp=0;
    int ans=0;
    for(int i=0;i<str.size();i++){
        if(s.count(str[i])){
            temp++;
            ans=max(ans,temp);
        }
        else temp=0;
    }
    cout<<ans;
}

