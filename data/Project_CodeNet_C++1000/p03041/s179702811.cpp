#include <cctype>
#include <iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    char s[n];
    for(int i=0;i<n;i++){
        cin>>s[i];
    }
    s[k-1]=tolower(s[k-1]);
    for(int i=0;i<n;i++){
        std::cout << s[i];
    }
}
