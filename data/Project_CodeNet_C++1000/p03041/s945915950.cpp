#include <iostream>

using namespace std;

int main()
{
    int n,k;
    string str;
    cin>>n>>k>>str;
    str[k-1] = str[k-1]-'A'+'a';
    cout<<str<<endl;
    return 0;
}
