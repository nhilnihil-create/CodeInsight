#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int len=s.size();
    if(len==2){
        cout << s << endl;
    }
    else {
            reverse(s.begin(),s.end());
        cout << s << endl;
    }
}
