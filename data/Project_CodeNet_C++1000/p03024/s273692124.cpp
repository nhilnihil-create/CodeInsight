
#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int c = count(s.cbegin(), s.cend(), 'o');
    
    if (c+(15-s.size())>=8){
        cout<<"YES";
    }
    else{
        cout<<"NO";
    }

}