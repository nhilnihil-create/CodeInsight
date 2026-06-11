#include<bits/stdc++.h>

using namespace std;

set<char>s;

int main()
{
    int n;
    char c[101];
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>c[i];
        s.insert(c[i]);
    }
    if(s.size()==3) cout<<"Three";
    else cout<<"Four";
    return 0;
}
