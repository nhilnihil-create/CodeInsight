#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    unsigned long long int n;
    cin>>n;
    char index;
    for(int i=0;i<s.size()&&n>0;i++)
    {
        if(s[i]=='1'){
            index=s[i];
            n--;
            continue;
        }
        else
        {
            index=s[i];
            break;
        }
    }
    cout<<index;
}