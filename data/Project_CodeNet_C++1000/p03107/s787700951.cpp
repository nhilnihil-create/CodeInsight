#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length(),zero=0,one=0;
    for(int i=0;i<n;i++){
        if(s[i]=='0'){
            zero++;
        }
        else one++;
    }
    cout<<n-abs(zero-one);
    return 0;
}
