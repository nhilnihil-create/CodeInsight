#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    cin >> s;
    int a=0,b=0,c=0;

    for(int i=0;i<s.size();i++){
        if(s[i]=='a') a++;
        else if(s[i]=='b') b++;
        else c++;
    }

    int u=s.size()/3+(s.size()%3?1:0),d=s.size()/3;
    if(a<=u && b<=u && c<=u && a>=d && b>=d && c>=d) cout << "YES" << endl;
    else cout << "NO" << endl;

    return 0;
}