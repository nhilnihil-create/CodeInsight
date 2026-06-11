#include <bits/stdc++.h>
using namespace std;
int main(void){
    long long int i=0,j,c=0,k;
    string s,t,s1;
    cin >> s >> t;
    c=s.size();
    for(i=0;i<c;i++)
    {
        s1=s[c-1];
        s=s.erase(c-1,1);
        s=s1+s;
        if(s==t)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;

}
