/*
ID: hafiz.i1
TASK: milk2
LANG: C++
*/
#include<bits/stdc++.h>

#define ll long long
#define debug(x) cout<<x<<"DE"<<endl;

using namespace std;



int main()
{
//    freopen("milk2.in", "r", stdin);
//    freopen("milk2.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;int x=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        for(int j=i;j<s.size();j++){
            if(s[j]=='A'||s[j]=='T'||s[j]=='G'||s[j]=='C'){x=max(x,j-i+1);}
            else break;
        }
    }
    cout<<x<<endl;
}
