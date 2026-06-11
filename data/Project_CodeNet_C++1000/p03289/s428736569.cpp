#include <iostream>

using namespace std;

int main()
{
    string s;
    cin>>s;
    int n=s.length(),sum=0;
    if(s[0]=='A' && s[1]>='a' && s[1]<='z' && s[n-1]>='a' && s[n-1]<='z'){
        for(int i=2;i<n-1;i++){
            if(s[i]!='C' && s[i]>='A' && s[i]<='Z')
                break;
            if(s[i]=='C')sum++;
        }
        if(sum==1) cout<<"AC";
        else cout<<"WA";

    }
    else cout<<"WA";
    return 0;
}
