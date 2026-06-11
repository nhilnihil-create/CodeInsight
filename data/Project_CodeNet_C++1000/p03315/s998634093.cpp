#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    int a=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='+'){
            a++;
        }else{
            a--;
        }
    }
    cout<<a<<endl;
}