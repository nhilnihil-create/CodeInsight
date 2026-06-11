#include<bits/stdc++.h>
using namespace std;
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
typedef long long ll;
int main()
{
    optimize();
    string st;
    cin>>st;
    string s=st.substr(5,2);
    if(s=="01"||s=="02"||s=="03"||s=="04")
        cout<<"Heisei"<<"\n";
    else
        cout<<"TBD"<<"\n";
    return 0;

}
