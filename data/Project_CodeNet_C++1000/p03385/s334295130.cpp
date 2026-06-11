#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(s.compare("abc") == 0){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
    return 0;
}
