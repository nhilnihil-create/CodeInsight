#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin>>s;
    sort(s.begin(),s.end());
    if(s=="abc"){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }
}